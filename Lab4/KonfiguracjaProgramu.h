#pragma once

#include <iostream>
#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>
#include <vector>

namespace po = boost::program_options;
namespace pt = boost::property_tree;
namespace fs = boost::filesystem;

class KonfiguracjaProgramu {
private:
    std::string p_nazwapliku;
    std::vector<double> p_A;
    std::vector<double> p_B;
    int p_k;
    double p_e;
    double p_K;
    double p_Ti;
    double p_Td;
    double p_amp;
    int p_okres;
    int p_start;
    int p_koniec;
    std::string p_plikZapisu;
public:
    KonfiguracjaProgramu(const std::string& nazwapliku) : p_nazwapliku(nazwapliku) {}
    bool wczytajKonfiguracje(int argc, const char* argv[], std::vector<double>& A,
        std::vector<double>& B, int& k, double& e, double& K, double& Ti, double& Td, double& amp,
        int& okres, int& start, int& koniec);
    bool zapiszKonfiguracje();
};