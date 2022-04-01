#include <DataBase.h>

using namespace Data::UniBase;

auto parse_args(char** begin, char** end) {
    char** arg = std::find(begin, end, std::string("-preset"));
    if(arg != end && ++arg!=end) {
        char argument = *(*arg);
        switch(argument){
            case '1': {
                Writer<>::Write();
                Collector::Collect();
                std::cout << "Do you want to read list?[y\\n]\n";
                char answer = ' ';
                std::cin >> answer;
                if (answer == 'y') { Reader::Read(); }
                else { return; }
            }
            case '2': {
                Editor::Edit();
                std::cout<<"Do you want to read list?[y\\n]\n";
                char answer = ' ';
                std::cin>>answer;
                if(answer=='y') { Reader::Read(); }
                else { return; }
            }
            case '3':
                Reader::Read();
            case '4': {
                Reader::Read();
                Writer<>::Write();
                Collector::Collect();
                Editor::Edit();
                Reader::Read();
            }   
        };
    } 
    else { throw std::runtime_error("Not enough arguments"); }
}

int main(int argc, char** argv) {
    parse_args(argv, argv+argc);
    return 0;
}
