namespace Data::UniBase
{
    class Deleter
    {
        static void Eraser(const std::string& filename, int arg) {
            Buffer::fill_buff(filename);
            std::vector<std::string> vec {};
            std::string str{};
            std::ifstream buff("buffer");
            while(getline(buff, str)) { vec.push_back(str); }
            if(std::size(vec)==0){
                buff.close();
                return;
            }
            vec.erase(vec.begin() + (arg-1));
            std::ofstream file(filename, std::ios::trunc);
            for(int i{}; i<std::size(vec); i++) {
                file<<vec[i];
            }
            file.close();
        }
    public: 
        static void Delete() {
            std::cout<<"Type number of line, which you want to delete\n";
            int arg{};
            std::cin>>arg;
            Eraser("name", arg);
            Eraser("vendor", arg);
            Eraser("cost", arg);
            std::cout<<"Success\n";
        }
        Deleter() = default;
        ~Deleter() = default;
    };
}