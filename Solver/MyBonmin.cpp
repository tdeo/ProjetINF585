// (C) Copyright Carnegie Mellon University 2006, 2007
// All Rights Reserved.
// This code is published under the Common Public License.
//
// Authors :
// P. Bonami, Carnegie Mellon University
//
// Date :  03/17/2006

#if defined(_MSC_VER)
// Turn off compiler warning about long names
#  pragma warning(disable:4786)
#endif
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>

#include "/home/thierry/Bonmin-stable/build/include/coin/CoinTime.hpp"
#include "/home/thierry/Bonmin-stable/build/include/coin/CoinError.hpp"

#include "/home/thierry/Bonmin-stable/build/include/coin/BonOsiTMINLPInterface.hpp"
#include "/home/thierry/Bonmin-stable/build/include/coin/BonIpoptSolver.hpp"
#include "MyTMINLP.hpp"
#include "/home/thierry/Bonmin-stable/build/include/coin/BonCbc.hpp"
#include "/home/thierry/Bonmin-stable/build/include/coin/BonBonminSetup.hpp"

#include "/home/thierry/Bonmin-stable/build/include/coin/BonOACutGenerator2.hpp"
#include "/home/thierry/Bonmin-stable/build/include/coin/BonEcpCuts.hpp"
#include "/home/thierry/Bonmin-stable/build/include/coin/BonOaNlpOptim.hpp"
#define REDIRECT

using namespace std;

int main(int argc, char** argv) {
	string mon_fichier = "/home/thierry/Projet_INF585/projet/data.txt"; // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
	ifstream fichier(mon_fichier.c_str(), ios::in);
	if (!fichier) // si l'ouverture a réussi
	{
		cerr << "Erreur à l'ouverture !" << endl;
	}

	//WindowsErrorPopupBlocker();

	using namespace Ipopt;
	using namespace Bonmin;
	
	string mon_fichier_config = "/home/thierry/Projet_INF585/projet/config.txt";
	ifstream fichier_config(mon_fichier_config.c_str(), ios::in);
	if (!fichier_config) // si l'ouverture a réussi
	{	
		cerr << "Erreur à l'ouverture !" << endl;
	}
	
	string contenu_config;
	getline(fichier_config, contenu_config);
	//cout << contenu_config;
	int timeLimit = stoi(contenu_config);
	getline(fichier_config, contenu_config);
	//cout << contenu_config;
	int nconfig = stoi(contenu_config);
	
	
	//std::cout << "How many configurations do you want ?" << std::endl;
	//std::cin >> nconfig;

	for (int j = 0; j < nconfig; j++) {

		SmartPtr<MyTMINLP> tminlp = new MyTMINLP;

		string contenu; // déclaration d'une chaîne qui contiendra la ligne lue
		getline(fichier, contenu); // on met dans "contenu" la ligne
		tminlp->linType = stoi(contenu);
		getline(fichier, contenu);
		tminlp->varNum = stoi(contenu);
		getline(fichier, contenu);
		tminlp->varType = stoi(contenu);
		getline(fichier, contenu);
		tminlp->W = stod(contenu);

		for (int i = 0; i < tminlp->varNum; i++) {
			if (tminlp->linType == 0) {
				getline(fichier, contenu);
				tminlp->a.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->b.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->c.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->d.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->p.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->q.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->U.push_back(stod(contenu));
			} else {
				getline(fichier, contenu);
				tminlp->a.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->b.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->c.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->d.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->w.push_back(stod(contenu));
				getline(fichier, contenu);
				tminlp->U.push_back(stod(contenu));
			}
		}

		std::string nconf;
		std::ostringstream convert;
		convert << j;
		nconf = convert.str();
		std::string temp = "/home/thierry/Projet_INF585/projet/output";
		nconf = temp.append(nconf);
		nconf = nconf.append(".log");

		char * nomfichier = new char[nconf.length() + 1];
		std::strcpy(nomfichier, nconf.c_str());
		

#ifdef REDIRECT
		FILE * fp = fopen(nomfichier, "w");
		tminlp->initializeData(fp);
		CoinMessageHandler handler(fp);
		BonminSetup bonmin(&handler);
#else
		BonminSetup bonmin;
#endif

		bonmin.initializeOptionsAndJournalist();
		//Register an additional option
		bonmin.roptions()->AddStringOption2("print_solution",
				"Do we print the solution or not?", "yes", "no",
				"No, we don't.", "yes", "Yes, we do.",
				"A longer comment can be put here");

		// Here we can change the default value of some Bonmin or Ipopt option
		bonmin.options()->SetNumericValue("bonmin.time_limit", timeLimit); //changes bonmin's time limit
		bonmin.options()->SetStringValue("mu_oracle", "loqo");

		//Here we read several option files
		bonmin.readOptionsFile("Mybonmin.opt");
		bonmin.readOptionsFile(); // This reads the default file "bonmin.opt"
		
		getline(fichier_config, contenu_config);
		bonmin.readOptionsString("bonmin.algorithm "+contenu_config+"\n");
		//cout << "bonmin.algorithm "+contenu_config << endl;
		
		getline(fichier_config, contenu_config);
		bonmin.readOptionsString("bonmin.num_resolve_at_root "+contenu_config+"\n");
		//cout << "bonmin.num_resolve_at_root "+contenu_config << endl;
		
		getline(fichier_config, contenu_config);
		bonmin.readOptionsString("bonmin.num_resolve_at_node "+contenu_config+"\n");
		//cout << "bonmin.num_resolve_at_node "+contenu_config << endl;
		
		getline(fichier_config, contenu_config);
		bonmin.readOptionsString("bonmin.variable_selection "+contenu_config+"\n");
		//cout << "bonmin.variable_selection "+contenu_config << endl;
		
		/*
		 int alg;
		 std::cout << "Which algorithm do you want to choose ? (BB=1, OA=2, QG=3, Hyb=4)" << std::endl;
		 std::cin >> alg;

		 if (alg == 1) {
		 // Options can also be set by using a string with a format similar to the bonmin.opt file
		 bonmin.readOptionsString("bonmin.algorithm B-BB\n");
		 }
		 else if (alg == 2) {
		 // Options can also be set by using a string with a format similar to the bonmin.opt file
		 bonmin.readOptionsString("bonmin.algorithm B-OA\n");
		 }
		 else if (alg == 3) {
		 // Options can also be set by using a string with a format similar to the bonmin.opt file
		 bonmin.readOptionsString("bonmin.algorithm B-QG\n");
		 }
		 else if (alg == 4) {
		 // Options can also be set by using a string with a format similar to the bonmin.opt file
		 bonmin.readOptionsString("bonmin.algorithm B-Hyb\n");
		 }

		 std::string nr;
		 std::cout << "How many trials to solve the root node with different starting points ?" << std::endl;
		 std::cin >> nr;
		 nr = nr.append("\n");

		 std::string s = "bonmin.num_resolve_at_root ";
		 s = s.append(nr);
		 bonmin.readOptionsString(s);

		 std::string nn;
		 std::cout << "How many trials to solve a node of the tree with different starting points ?" << std::endl;
		 std::cin >> nn;
		 nn = nn.append("\n");

		 std::string t = "bonmin.num_resolve_at_node ";
		 t = t.append(nn);
		 bonmin.readOptionsString(t);

		 std::string vs;
		 std::cout << "Which variable selection type do you want to choose (most-fractional/strong-branching/...) ?" << std::endl;
		 std::cin >> vs;
		 vs = vs.append("\n");

		 std::string v = "bonmin.variable_selection ";
		 v = v.append(vs);
		 bonmin.readOptionsString(v);
		
		bonmin.readOptionsString("bonmin.algorithm B-BB\n");
		bonmin.readOptionsString("bonmin.num_resolve_at_root 0\n");
		bonmin.readOptionsString("bonmin.num_resolve_at_node 0\n");
		bonmin.readOptionsString("bonmin.variable_selection most-fractional\n");
		*/

			
		
		
		


		// Now we can obtain the value of the new option
		int printSolution;
		bonmin.options()->GetEnumValue("print_solution", printSolution, "");
		if (printSolution == 1) {
			tminlp->printSolutionAtEndOfAlgorithm();
		}

		//Now initialize from tminlp
		bonmin.initialize(GetRawPtr(tminlp));

		//Set up done, now let's branch and bound
		double time1 = CoinCpuTime();
		try {
			Bab bb;
			//std::cout << "1" << std::endl;
			bb(bonmin); //process parameter file using Ipopt and do branch and bound using Cbc
			//std::cout << "3" << std::endl;
			
		} catch (TNLPSolver::UnsolvedError *E) {
			//There has been a failure to solve a problem with Ipopt.
			std::cerr << "Ipopt has failed to solve a problem" << std::endl;
		} catch (OsiTMINLPInterface::SimpleError &E) {
			std::cerr << E.className() << "::" << E.methodName() << std::endl
					<< E.message() << std::endl;
		} catch (CoinError &E) {
			std::cerr << E.className() << "::" << E.methodName() << std::endl
					<< E.message() << std::endl;
		}

		
		fclose(fp);
	}
	return 0;
}

