namespace Data::UniBase
{
    template<typename ...>
    class Writer
    {
        protected: static int NumofObj()
        {
            std::ifstream idoc(path, std::ios::in);
            std::string str;
            while(getline(idoc, str)) 
            {
                Data.push_back(str);
            }
            idoc.close();
            return size(Data);
        }
        
        public: static void Write()
        {
            std::ofstream Name("name", std::ios::app);
            std::ofstream Code("vendor", std::ios::app);
            std::ofstream Cost("cost", std::ios::app);
            std::string str{};
            doc<<NumofObj()+1<<"    ";
            std::cout<<"Enter name of product: \n";
            getline(std::cin, str);
            Name<<str<<'\n';
            Name.close();
            std::cout<<"Enter vendor code: \n";
            getline(std::cin, str);
            Code<<str<<'\n';
            Code.close();
            std::cout<<"Enter cost: \n";
            getline(std::cin, str);
            Cost<<str<<'\n';
            Cost.close();
            doc.close();
        }
        
        public: Writer() = default;
        public: virtual ~Writer() = default;
    };
}