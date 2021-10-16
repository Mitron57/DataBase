namespace Data::UniBase
{
    class UniBase
    {
        private: void Whereisfile()
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
            else{ std::cout<<"File has been successfully opened."<<'\n'; }
        }
        public: UniBase()
        {
            Whereisfile();
            doc.open(path, std::ios::app);
            Checker();
        }
    };
}