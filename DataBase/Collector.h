namespace Data::UniBase
{
    class Collector
    {
        public: static auto NumOfObj() -> std::uint32_t
        {
            std::vector<std::string> vec;
            std::ifstream idoc("Data", std::ios::in);
            std::string str{};
            while(getline(idoc, str))
            {
                vec.push_back(str);
            }
            idoc.close();
            return std::size(vec);
        }
        
        private: static auto GetData(const std::string& path_to_file, std::vector<std::string>& vec) -> void
        {
            std::ifstream FileName(path_to_file, std::ios::in);
            std::string str;
            while(getline(FileName, str))
            {
                vec.push_back(str);
            }
            FileName.close();
        }
        
        public: static auto Collect() -> void
        {
            std::ofstream d ("Data", std::ios::trunc);
            std::vector<std::string> name {};
            std::vector<std::string> code {};
            std::vector<std::string> cost {};
            GetData("name", name);
            GetData("vendor", code);
            GetData("cost", cost);
            auto num = NumOfObj();
            for(int i{}; i<std::size(name); i++)
            {
                num += 1;
                d<<num<<"    "<<name[i]<<"    "<<code[i]<<"    "<<cost[i]<<'\n';
            }
            d.close();
        }
        
        public: Collector() = default;
        public: ~Collector() = default;
    };
}