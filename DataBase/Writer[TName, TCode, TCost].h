namespace Data::UniBase
{
    template <typename TName, typename TCode, typename TCost>
    class Writer<TName, TCode, TCost>
    {
        public:
        [[maybe_unused]] static auto Input(const TName& name, const TCode& vendor_code, const TCost& cost) -> void
        {
            std::ofstream Name("name", std::ios::app);
            std::ofstream Code("vendor", std::ios::app);
            std::ofstream Cost("cost", std::ios::app);
            Name<<name<<'\n';
            Name.close();
            Code<<vendor_code<<'\n';
            Code.close();
            Cost<<cost<<'\n';
            Cost.close();
        }

        public: Writer() = default;
        public: virtual ~Writer() = default;
    };
}