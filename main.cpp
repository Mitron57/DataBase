#include <DataBase.h>

using namespace Data::UniBase;

int main() {
    std::cout<<"Welcome to my DataBase!\nThis project is experimental and has no purposes\n"
               "besides demonstrating my project to my school.\n"
               "Type Help to see list of commands.\n";
    while(1) {
        std::cout<<">>";
        std::string user_command {};
        std::cin >> user_command;
        if(user_command=="Read") { Reader::Read(); }
        else if(user_command=="Write") {
            Writer::Write();
            Collector::Collect();
        }
        else if(user_command=="Help") {
            std::cout<<"This program has following commands:\n"
                       "1. Read - read a row/rows from file.\n"
                       "2. Write - write data in file.\n"
                       "3. Edit - edit a row.\n"
                       "4. Delete - delete a row.\n"
                       "5. Exit - exit from program.\n"
                       "6. Clear - clear your screen.\n"
                       "Note: answer the questions by typing y or n.\n";
        }
        else if(user_command=="Edit") { Editor::Edit(); }
        else if(user_command=="Delete") { Eraser::Erase(); }
        else if(user_command=="Clear") { system("clear"); }
        else if(user_command=="Exit") { break; }
        user_command.clear();
    }
    return 0;
}
