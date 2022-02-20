#include <iostream>
using namespace std;

// https://bukovel.com/ru/ski/hire
class SkiRent // аренда снаряжения
{
public:
    double rentBoots(int feetSize, int skierLevel) // ботинки
    {
        double price = 159.99;
        // if (feetSize < 40) price -= 20; // скидка для детей
        return price;
    }

    double rentHelmet(int feetSize, int skierLevel) // шлем
    {
        return 120;
    }

    double rentSki(int weight, int skierLevel) // лыжи
    {
        return 180;
    }

    double rentSkiPoles(int height) // лыжные палки
    {
        return 50;
    }
};

// https://bukovel24.com/ru/skipass
class SkiResortTicketSystem // покупка билетов
{
public:
    double buyOneDayTicket()
    {
        return 1100;
    }

    double buyTwoDaysTicket()
    {
        return 2050;
    }

    double buyThreeDaysTicket()
    {
        return 2900;
    }

    double buyFourDaysTicket()
    {
        return 3800;
    }

    double buyFiveDaysTicket()
    {
        return 4600;
    }

    double buySixDaysTicket()
    {
        return 5150;
    }

    double buySevenDaysTicket()
    {
        return 5800;
    }
};

// https://bukovel24.com/uk/hotels
class HotelBookingSystem // заказ гостиницы
{
public:
    double bookRoom(int roomQuality) {
        switch (roomQuality) {
        case 3:
            return 5670 / 2;
        case 4:
            return 9240 / 2;
        case 5:
            return 41500 / 2;
        default:
            throw "roomQuality should be in range [3;5]";
        }
    }
};

class SkiResortFacade // реализация паттерна "фасад"
{
    SkiRent sr;
    SkiResortTicketSystem ts;
    HotelBookingSystem hb;

public:
    double haveAVeryVeryNiceTime(int height, int weight, int feetSize, int skierLevel, int roomQuality)
    {
        double skiPrice = sr.rentSki(weight, skierLevel);
        double skiBootsPrice = sr.rentBoots(feetSize, skierLevel);
        double polesPrice = sr.rentSkiPoles(height);
        double skiPassPrice = ts.buySevenDaysTicket();
        double hotelPrice = hb.bookRoom(roomQuality);

        return skiPrice + skiBootsPrice + polesPrice + skiPassPrice + hotelPrice;
    }

    double haveALittleFunWithYourOwnEquipmentAndTent()
    {
        double skiPassPrice = ts.buyOneDayTicket();
        return 0 + 0 + 0 + skiPassPrice + 0;
    }
};

int main()
{
    SkiResortFacade facade;
    double vacationPrice = facade.haveAVeryVeryNiceTime(177, 80, 43, 0, 5);
    // double vacationPrice = facade.haveAVeryVeryNiceTime(177, 80, 43, 0, 4);
    // double vacationPrice = facade.haveAVeryVeryNiceTime(177, 80, 43, 0, 3);
    // double vacationPrice = facade.haveALittleFunWithYourOwnEquipmentAndTent();
    cout << "Price: " << vacationPrice << " UAH\n";
}