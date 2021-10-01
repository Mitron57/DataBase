namespace Data::UniBase
{
    class Writer: public UniBase
    {
        public: static void Write()
        {
            std::string str;
            std::cout<<"Enter name of product: ";
            getline(std::cin, str);
            doc<<str;
        }
        public: Writer() { Write();};
    };
}