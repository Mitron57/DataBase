namespace Data::UniBase
{
    class Writer: public UniBase
    {
        //TODO: сделать функцию для проверки номера объекта
        public: static int ctnofo() //Check the number of object
        {
            std::string str{};
            std::vector<std::string> num{};
            while (getline(doc, str))
            {
                num.push_back(str);
            }
            for (int i{}; i<size(num); i++){std::cout<<'\n'<<num[i]<<'\n';}
            doc.close();
            return size(num);
        }
        
        public: static void Write()
        {
            std::string str{};
            doc.open(path, std::ios::app);
            std::cout<<ctnofo()<<'\n';
            doc<<ctnofo()+1<<"    ";
            std::cout<<"Enter name of product: ";
            getline(std::cin, str);
            doc<<str<<'\n';
        }
        public: Writer() { Write();};
    };
}