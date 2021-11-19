namespace Data::UniBase
{
    template <typename TName, typename TCode, typename TCost>
    class Writer<TName, TCode, TCost>
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
        
        public: static void Write(TName name, TCode vendor_code, TCost cost)
        {
            std::ofstream Name("name", std::ios::app);
            std::ofstream Code("vendor", std::ios::app);
            std::ofstream Cost("cost", std::ios::app);
            doc<<NumofObj()+1<<"    ";
            Name<<name<<'\n';
            Name.close();
            Code<<vendor_code<<'\n';
            Code.close();
            Cost<<cost<<'\n';
            Cost.close();
            doc.close();
        }

        public: Writer() = default;
        public: virtual ~Writer() = default;
    };
}