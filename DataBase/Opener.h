namespace Data::UniBase
{
    class Opener
    {
        /*private: static void File()
        {
            auto* ans = new std::string;
            std::cout<<"Do you want to read your file?\n";
            std::cin>>*ans;
            if(*ans == "no" || *ans == "No")
            {
                path = "Data";
            }
            else if (*ans == "yes" || *ans == "Yes")
            {
                Whereisfile();
            }
            else
            {
                std::cout<<"Incorrect answer\n";
                File();
                delete ans;
            }
            delete ans;
        }*/
        
        private: static void Whereisfile()
        {
            std::cout<<"Type the path to file: "<<'\n';
            getline(std::cin, path);
        }

        private: static void Checker()
        {
            if(!doc.is_open())
            {
                std::cout<<"Unexpected error. File hasn`t been opened."<<'\n';
                abort();
            }
            else { std::cout<<"File has been successfully opened."<<'\n'; }
        }
        public: Opener()
        {
            Whereisfile();
            doc.open(path, std::ios::trunc);
            Checker();
        }
    };
}