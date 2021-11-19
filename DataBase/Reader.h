namespace Data::UniBase
{
    class Reader: public Writer<>
    {
        static std::string Chooser(const std::string& ans)
        {
            if(ans == "Yes"|| ans == "yes") { return "yes"; }
            else if(ans == "No" || ans == "no") { return "no"; }
            else { std::cout<<"Incorrect answer, try again\n"; return "inc"; }
        }
        
        private: static bool ReadCurObj(const int& num)
        {
            if(num<=size(Data) && num>=0){ std::cout<<"This object is: "<< Data[num-1]; return true;}
            else { return false; }
        }
        
        public: static void Read()
        {
            Data = {};
            Writer<>::NumofObj();
            std::string answer{};
            int num{};
            std::cout<<"Do you want to read current object?\n";
            std::cin>>answer;
            if(Chooser(answer)=="yes")
            {
                std::cout<<"Type the number of current object: \n";
                std::cin>>num;
                if(!ReadCurObj(num))
                { 
                    std::cout<<"Can`t find object with this number, please, try again\n";
                    std::cout<<"Type the number of current object: \n";
                    std::cin>>num;
                    ReadCurObj(num);
                }
            }
            else if (Chooser(answer)=="no")
            {
                std::cout<<"Do you want to read whole file?\n";
                std::cin>>answer;
                if(Chooser(answer)=="yes")
                {
                    std::cout<<"File contains following objects: \n";
                    for(int i{}; i<size(Data); i++)
                    {
                        std::cout<<Data[i]<<'\n';
                    }
                }
                else if(Chooser(answer)=="no"){ abort();}
            }
            else if(Chooser(answer)=="inc"){ std::cin>>answer; Chooser(answer); }
        }
        
        public: Reader() = default;
        public: virtual ~Reader() = default;
    };
}