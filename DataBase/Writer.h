namespace Data::UniBase
{
    class Writer
    {
        public: static auto Write() -> void
        {
            std::ofstream Name("name", std::ios::app);
            std::ofstream Code("vendor", std::ios::app);
            std::ofstream Cost("cost", std::ios::app);
            std::string str{};
            std::cout<<"Enter name of product:\n";
            std::cin.clear();
            getline(std::cin, str);
            Name<<str<<'\n';
            Name.close();
            std::cout<<"Enter vendor code:\n";
            getline(std::cin, str);
            Code<<str<<'\n';
            Code.close();
            std::cout<<"Enter cost:\n";
            getline(std::cin, str);
            Cost<<str<<'\n';
            Cost.close();
        }
        
        public: Writer() = default;
        public: virtual ~Writer() = default;
    };
}