namespace Data::UniBase
{
    class Reader: public Collector
    {
        static auto Fill(std::vector<std::string>& vec) -> void
        {
            std::ifstream idoc("Data", std::ios::in);
            std::string str {};
            while(getline(idoc, str))
            {
                vec.push_back(str);
            }
            idoc.close();
        }
        
        static auto Choose(const std::string& ans) -> bool
        {
            return (ans == "Y"|| ans == "y") || !(ans == "N" || ans == "n");
        }
        
        public: static auto Read() -> void
        {
            doc.close();
            Collector::Collect();
            std::vector<std::string> data{};
            Fill(std::forward<std::vector<std::string>&>(data));
            std::string answer{};
            std::cout<<"Do you want to read current object?\n";
            std::cin>>answer;
            switch(static_cast<int>(Choose(answer))) {
                case 1: {
                    std::cout<<"Type the number of current object: \n";
                    int num{};
                    std::cin>>num;
                    if(num <= std::size(data) && num > 0) { std::cout<<data[num-1]<<'\n'; }
                    else { std::cout<<"Can`t find object with this number\n"; }
                    break;
                }
                case 0: {   
                    std::cout<<"Do you want to read whole file?\n";
                    std::cin>>answer;
                    if(Choose(answer)) {
                        std::cout<<"File contains following objects: \n";
                        for(int i{}; i<std::size(data); i++) { std::cout<<data[i]<<'\n'; }
                    }
                    break;
                }
            }
        }
        
        public: Reader() = default;
        public: ~Reader() = default;
    };
}