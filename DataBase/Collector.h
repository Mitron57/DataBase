namespace Data::UniBase
{
    class Collector
    {
        private: static void GetData(const std::string& path_to_file, std::vector<std::string>& vec)
        {
            std::ifstream FileName(path_to_file, std::ios::in);
            std::string str {};
            while(getline(FileName, str))
            {
                vec.push_back(str);
            }
            FileName.close();
        }
        
        public: Collector()
        {
            doc.open(path, std::ios::trunc);
            std::vector<std::string> name {};
            std::vector<std::string> code {};
            std::vector<std::string> cost {};
            GetData("name", name);
            GetData("vendor", code);
            GetData("cost", cost);
            for(int i{}; i<size(name); i++)
            {
                doc<<name[i]<<"    "<<code[i]<<"    "<<cost[i]<<'\n';
            }
            doc.close();
        }
    };
}