namespace Data::UniBase
{
    class Collector
    {
        public: static auto NumOfRow() -> std::uint32_t
        {
            std::vector<std::string> vec {};
            std::ifstream idoc("Data", std::ios::in);
            std::string str{};
            while(getline(idoc, str)) { vec.push_back(str); }
            idoc.close();
            return std::size(vec);
        }
        
        private: static auto GetData(const std::string& path_to_file, std::vector<std::string>& vec) -> void
        {
            std::ifstream FileName(path_to_file, std::ios::in);
            std::string str{};
            while(getline(FileName, str)) { vec.push_back(str); }
            FileName.close();
        }
        
        public: static auto Collect() -> void
        {
            std::ofstream Data ("Data", std::ios::trunc);
            std::vector<std::string> name {}, code {}, cost {};
            std::async(GetData, "name", std::reference_wrapper(name)).wait();
            std::async(GetData, "vendor", std::reference_wrapper(code)).wait();
            std::async(GetData, "cost", std::reference_wrapper(cost)).wait();
            auto num = NumOfRow();
            for(int i{}; i<std::size(name); i++)
            {
                num += 1;
                Data << num << "    " << name[i] << "    " << code[i] << "    " << cost[i] << '\n';
            }
            Data.close();
        }
        
        public: Collector() = default;
        public: ~Collector() = default;
    };
}
