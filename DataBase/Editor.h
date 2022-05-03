namespace Data::UniBase
{
    class Editor
    {
        private: static auto GetData(const std::string& path_to_file, std::vector<std::string>& vec) -> void
        {
            std::ifstream FileName(path_to_file, std::ios::in);
            std::string str{};
            while(getline(FileName, str)) { vec.push_back(str); }
            FileName.close();
        }

        public: static auto Edit() -> void {
            std::vector<std::string> name{}, code{}, cost{};
            std::async(GetData, "name", std::reference_wrapper(name)).wait();
            std::async(GetData, "vendor", std::reference_wrapper(code)).wait();
            std::async(GetData, "cost", std::reference_wrapper(cost)).wait();
            int num{};
            std::string str{};
            std::cout << "Type number of a row you want to edit.\n>>";
            std::cin >> num;
            if(num>std::size(name)) {
                std::cout<<"Nothing to edit.\n";
                return;
            }
            std::cout << "If you don`t want to edit any parameter just press Enter to skip it.\n";
            std::cout << "Previous row: " << name[num-1] << " " << code[num-1] << " " << cost[num-1]<<'\n';
            std::cout << "Your row.\nName: ";
            std::cin.ignore();
            getline(std::cin, str);
            if(std::find(str.begin(), str.end(), '\n') != str.begin()) {
                name[num-1] = str;
            }
            str.clear();
            std::cout << "Vendor code: ";
            getline(std::cin, str);
            if(std::find(str.begin(), str.end(), '\n') != str.begin()) {
                code[num-1] = str;
            }
            str.clear();
            std::cout << "Cost: ";
            getline(std::cin, str);
            if(std::find(str.begin(), str.end(), '\n') != str.begin()) {
                cost[num-1] = str;
            }
            str.clear();
            std::ofstream Name("name", std::ios::trunc),
                          Code("vendor", std::ios::trunc),
                          Cost("cost", std::ios::trunc);
            for(int i{}; i<std::size(name); ++i) {
                Name << name[i] << '\n';
                Code << code[i] << '\n';
                Cost << cost[i] << '\n';
            }
        }
        public: Editor() = default;
        public: ~Editor() = default;
    };
}