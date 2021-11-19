namespace Data::UniBase
{
    class Editor: public Writer<>
    {
        //TODO: imagine solution to edit data.
        static void Edit()
        {
            std::string str{};
            int num {};
            Data = {};
            Writer<>::NumofObj();
            std::cout<<"Which object do you want to change?\n";
            std::cin>>num;
            std::cout<<"Current object is:"<<Data[num]<<'\n';
        }
        
        public: Editor() = default;

        public: ~Editor() override = default;
    };
}