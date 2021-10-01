namespace Data::UniBase
{
    class UniBase
    {
        private: static void Checker()
        {
            if(!doc.is_open()){std::cout<<"Unexpected error. File hasn`t been opened."<<'\n';}
            else{std::cout<<"File has successfully opened."<<'\n';}
        }
        public: UniBase()
        {
            doc.open("//home//zaha57//CLionProjects/DataBase/DataBase//Data.txt", std::ios::app);
            Checker();
        }
    };
}