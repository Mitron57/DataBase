namespace Data::UniBase
{
    class Reader: public Collector
    {
        static auto Fill(std::vector<std::string>& vec) -> void
        {
            std::ifstream idoc("Data", std::ios::in);
            std::string str {};
            while(getline(idoc, str)) { vec.push_back(str); }
            idoc.close();
        }
        
        static inline auto Choose(const std::string& ans) -> bool
        {
            return (ans == "Y"|| ans == "y") || !(ans == "N" || ans == "n");
        }
        
        public: static auto Read() -> void
        {
            Collector::Collect();
            std::vector<std::string> data{};
            Fill(std::reference_wrapper(data));
            std::string answer{};
            std::cout<<"Do you want to read concrete object?\n>>";
            std::cin>>answer;
            switch(static_cast<int>(Choose(answer))) {
                case 1: {
                    std::cout<<"Type the number of concrete object:\n>>";
                    int num{};
                    std::cin >> num;
                    if(num <= std::size(data) && num > 0) { std::cout << data[num-1] << '\n'; }
                    else { std::cout << "Can`t find object with this index\n"; }
                    break;
                }
                case 0: {   
                    std::cout << "Do you want to read whole file?\n>>";
                    std::cin >> answer;
                    if(Choose(answer)) {
                        std::cout<<"File contains following objects:\n";
                        for(const auto& line: data) { std::cout << line << '\n'; }
                    }
                    break;
                }
            }
        }
        
        public: Reader() = default;
        public: ~Reader() = default;
    };
}
