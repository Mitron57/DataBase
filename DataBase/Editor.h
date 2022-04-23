namespace Data::UniBase
{
    class Editor
    {
        protected: static inline auto Exist(const int& num, const unsigned int& size) -> bool
        {
            return (num-1>=0 && num-1<size);
        }
        
        protected: static auto Convert(const std::string& str) -> char
        {
            if(str == "Name" || str == "name")
                return 'n';
            else if (str == "Code" || str == "code")
                return 'd';
            else if (str == "Cost" || str =="cost")
                return 's';
            return ' ';
        }
        
        public: static auto Edit() -> void
        {
            std::string str{};
            int num {};
            std::cout<<"What do you want to change?\nName\nCode\nCost\n";
            std::cin>>str;
            std::vector<std::string> vec{};
            switch(Convert(str))
            {
                case 'n':
                {
                    Buffer::fill_buff("name");
                    std::ofstream Name("name", std::ios::trunc);
                    std::ifstream BuffIn("buffer", std::ios::in);
                    str.clear();
                    while (getline(BuffIn, str)) { vec.push_back(str); }
                    str.clear();
                    std::cout << "What name do you want to change?(type number)\n";
                    std::cin >> num;
                    if (Exist(num, std::size(vec))) {
                        std::cout << "Current name is: " << vec[num - 1] << '\n';
                        std::cout << "New name is: ";
                        std::cin >> str;
                        vec[num - 1] = str;
                        for (int i{}; i < std::size(vec); i++) {
                            Name << vec[i] << '\n';
                        }
                    }
                    else {std::cout<<"Can not find a row with this index\n";}
                    vec.clear();
                    BuffIn.close();
                    Name.close();
                    break;
                }

                case 'd':
                {
                    Buffer::fill_buff("vendor");
                    std::ofstream Code("vendor", std::ios::trunc);
                    std::ifstream BuffInp("buffer", std::ios::in);
                    str.clear();
                    while (getline(BuffInp, str)) { vec.push_back(str); }
                    str.clear();
                    std::cout << "What vendor code do you want to change?(type number)\n";
                    std::cin >> num;
                    if (Exist(num, std::size(vec))) {
                        std::cout << "Current vendor code is: " << vec[num - 1] << '\n';
                        std::cout << "New vendor code is: ";
                        std::cin >> str;
                        vec[num - 1] = str;
                        for (int i{}; i < std::size(vec); i++) {
                            Code << vec[i] << '\n';
                        }
                    }
                    else { std::cout<<"Can not find a row with this index\n"; }
                    vec.clear();
                    Code.close();
                    BuffInp.close();
                    break;
                }
                
                case 's':
                {
                    Buffer::fill_buff("cost");
                    std::ofstream Cost("cost", std::ios::trunc);
                    std::ifstream BuffInput("buffer", std::ios::in);
                    str.clear();
                    while(getline(BuffInput, str)) { vec.push_back(str); }
                    str.clear();
                    std::cout<<"What cost do you want to change?(type number)\n";
                    std::cin>>num;
                    if (Exist(num, std::size(vec))) {
                        std::cout << "Current cost is: " << vec[num - 1] << '\n';
                        std::cout << "New cost is: ";
                        std::cin >> str;
                        vec[num - 1] = str;
                        for (int i{}; i < std::size(vec); i++) {
                            Cost << vec[i] << '\n';
                        }
                    }
                    else { std::cout<<"Can not find a row with this index\n"; }
                    vec.clear();
                    Cost.close();
                    BuffInput.close();
                    break;
                }
                default: std::cout<<"Incorrect answer\n";
            }
        }
        
        public: Editor() = default;
        public: ~Editor() = default;
    };
}