#include <DataBase.h>

using namespace Data::UniBase;

int main()
{
    /*auto name = "Intel Core I5 9600KF OEM";
    auto vendor_code = 1729837923;
    auto cost = 100;*/
    Opener();
    Writer<>::Write();
    Collector();
   // Writer<std::string, int, int>::Write(name, vendor_code, cost);
    Reader::Read();
    return 0;
}
