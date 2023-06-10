#include "KonfiguracjaProgramu.h"

bool KonfiguracjaProgramu::wczytajKonfiguracje(int argc, const char* argv[], std::vector<double> &A, 
    std::vector<double> &B, int &k, double &e, double &K, double &Ti, double &Td, double &amp,
    int &okres, int& start, int& koniec)
{
    po::options_description desc("Dostêpne opcje");
    desc.add_options()
        ("A", po::value<std::vector<double>>(&p_A)->multitoken(), "ModelARX - Wektor A ")
        ("B", po::value<std::vector<double>>(&p_B)->multitoken(), "ModelARX - Wektor B")
        ("k", po::value<int>(&p_k), "ModelARX - OpóŸnienie transportowe")
        ("e", po::value<double>(&p_e), "ModelARX - Obiekt formuj¹cy rozk³ad normalny")
        ("K", po::value<double>(&p_K), "RegulatorPID - Wzmocnienie")
        ("Ti", po::value<double>(&p_Ti), "RegulatorPID - Sta³a ca³kuj¹ca")
        ("Td", po::value<double>(&p_Td), "RegulatorPID - Sta³a ró¿niczkuj¹ca")
        ("amp", po::value<double>(&p_amp), "Generator Sygna³u - Amplituda")
        ("okres", po::value<int>(&p_okres), "Generator Sygna³u - Okres")
        ("start", po::value<int>(&p_start), "Generator Sygna³u - Start")
        ("koniec", po::value<int>(&p_koniec), "Generator Sygna³u - Koniec")
        ("plikZapisu", po::value<std::string>(&p_plikZapisu), "Plik zapisu ustawieñ");

    po::variables_map vm;

    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << desc << std::endl;
        return false;
    }

    po::notify(vm);

    if (vm.count("A") && vm.count("B") && vm.count("k") && vm.count("okres") &&
        vm.count("start") && vm.count("koniec") && vm.count("e") &&
        vm.count("K") && vm.count("Ti") && vm.count("Td") && vm.count("amp"))
    {
        A = p_A;
        B = p_B;
        k = p_k;
        okres = p_okres;
        start = p_start;
        koniec = p_koniec;
        e = p_e;
        K = p_K;
        Ti = p_Ti;
        Td = p_Td;
        amp = p_amp;

        return true;
    }
    else
    {
        if (!boost::filesystem::exists(p_nazwapliku))
        {
            return false;
        }
        try
        {
            pt::ptree tree;
            pt::read_json(p_nazwapliku, tree);

            if (!vm.count("A"))
            {
                if (tree.count("A") > 0)
                {
                    for (const auto& item : tree.get_child("A"))
                    {
                        p_A.push_back(item.second.get_value<double>());
                    }
                }
            }

            if (!vm.count("B"))
            {
                if (tree.count("B") > 0)
                {
                    for (const auto& item : tree.get_child("B"))
                    {
                        p_B.push_back(item.second.get_value<double>());
                    }
                }
            }

            if (!vm.count("k")) p_k = tree.get<int>("k");
            if (!vm.count("okres")) p_okres = tree.get<int>("okres");
            if (!vm.count("start")) p_start = tree.get<int>("start");
            if (!vm.count("koniec")) p_koniec = tree.get<int>("koniec");
            if (!vm.count("e")) p_e = tree.get<double>("e");
            if (!vm.count("K")) p_K = tree.get<double>("K");
            if (!vm.count("Ti")) p_Ti = tree.get<double>("Ti");
            if (!vm.count("Td")) p_Td = tree.get<double>("Td");
            if (!vm.count("amp")) p_amp - tree.get<double>("amp");
        }
        catch (const pt::json_parser_error& e)
        {
            return false;
        }
        A = p_A;
        B = p_B;
        k = p_k;
        okres = p_okres;
        start = p_start;
        koniec = p_koniec;
        e = p_e;
        K = p_K;
        Ti = p_Ti;
        Td = p_Td;
        amp = p_amp;

        return true;
    }
}

bool KonfiguracjaProgramu::zapiszKonfiguracje() {
    pt::ptree tree;

    pt::ptree treeA;
    for (const auto& value : p_A) 
    {
        pt::ptree item;
        item.put_value(value);
        treeA.push_back(std::make_pair("", item));
    }
    tree.add_child("A", treeA);

    pt::ptree treeB;
    for (const auto& value : p_B) 
    {
        pt::ptree item;
        item.put_value(value);
        treeB.push_back(std::make_pair("", item));
    }
    tree.add_child("B", treeB);

    tree.put("k", p_k);
    tree.put("okres", p_okres);
    tree.put("start", p_start);
    tree.put("koniec", p_koniec);
    tree.put("e", p_e);
    tree.put("K", p_K);
    tree.put("Ti", p_Ti);
    tree.put("Td", p_Td);
    tree.put("amp", p_amp);

    std::string plikZapisu = p_plikZapisu;
    std::string odp;
    if (plikZapisu.empty()) 
    {
        std::cerr << "\nPodaj nazwê pliku do zapisu konfiguracji: ";
        std::cin >> plikZapisu;
    }

    if (boost::filesystem::exists(plikZapisu)) 
    {
        std::cerr << "\nPlik " << plikZapisu << " ju¿ istnieje. Czy chcesz go nadpisaæ? (t/n): ";
        std::cin >> odp;
        if (odp != "t") 
        {
            std::cerr << "\nAnulowano zapis konfiguracji." << std::endl;
            return false;
        }
    }
    else 
    {
        boost::filesystem::path path(plikZapisu);
        boost::filesystem::path dir = path.parent_path();
        if (!boost::filesystem::exists(dir)) 
        {
            std::cerr << "\nPodany katalog nie istnieje. Czy chcesz go utworzyæ? (t/n): ";
            std::cin >> odp;
            if (odp != "t") 
            {
                std::cerr << "\nAnulowano zapis konfiguracji." << std::endl;
                return false;
            }
            if (!boost::filesystem::create_directories(dir)) 
            {
                std::cerr << "\nNie uda³o siê utworzyæ katalogu." << std::endl;
                return false;
            }
        }
    }

    try 
    {
        pt::write_json(plikZapisu, tree);
    }
    catch (const pt::json_parser_error& ex) 
    {
        std::cerr << "\nB³¹d zapisu pliku." << std::endl;
        return false;
    }
    return true;
}