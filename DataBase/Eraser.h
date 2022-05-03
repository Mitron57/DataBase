namespace Data::UniBase
{
    class Eraser
    {
        static void Delete(const std::array<std::string, 3>&& files, int arg) {
            for(const auto& file: files) {
                std::vector<std::string> data {};
                std::ifstream FileIn (file);
                std::string line{};
                while(getline(FileIn, line)) {
                    data.push_back(line);
                }
                FileIn.close();
                if(std::size(data)==0){
                    std::cout<<"Nothing to delete.\n";
                    return;
                }
                data.erase(data.begin() + (arg-1));
                std::ofstream FileOut(file, std::ios::trunc);
                for(const auto& l: data) {
                    FileOut<<l<<'\n';
                }
                FileOut.close();
            }
        }
    public: 
        static void Erase() {
            std::cout<<"Type number of line, which you want to delete.\n>>";
            int arg{};
            std::cin>>arg;
            std::array<std::string, 3> files {"name", "vendor", "cost"};
            std::async(Delete, std::move(files), arg).wait();
        }
        Eraser() = default;
        ~Eraser() = default;
    };
}
