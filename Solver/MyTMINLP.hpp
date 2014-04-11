// (C) Copyright Carnegie Mellon University 2006
// All Rights Reserved.
// This code is published under the Common Public License.
//
// Authors :
// P. Bonami, Carnegie Mellon University
//
// Date :  03/17/2006
#ifndef MyTNLP_HPP
#define MyTNLP_HPP
#include "/home/thierry/Bonmin-stable/build/include/coin/BonTMINLP.hpp"
#include <vector>

using namespace Ipopt;
using namespace Bonmin;
/** A C++ example for interfacing an MINLP with bonmin.
   * This class implements the following NLP :
  * \f[ 
    \begin{array}{l}
    \min - x_0 - x_1 - x_2 \\ 
    \mbox{s.t}\\
    (x_1 - \frac{1}{2})^2 + (x_2 - \frac{1}{2})^2 \leq \frac{1}{4} \\
    x_0 - x_1 \leq 0 \\
    x_0 + x_2 + x_3 \leq 2\\
    x_0 \in \{0,1\}^n \; (x_1, x_2) \in R^2 \; x_3 \in N
    \end{array}
    \f]
  */
    
class MyTMINLP : public TMINLP
{
public:
  /// Default constructor.
  MyTMINLP():
printSol_(false){}

  
  /// virtual destructor.
 virtual ~MyTMINLP(){}



  
	/** Copy constructor.*/   
  MyTMINLP(const MyTMINLP &other):
printSol_(other.printSol_){}
  /** Assignment operator. no data = nothing to assign*/
  //MyTMINLP& operator=(const MyTMINLP&) {}

  
  /** \name Overloaded functions specific to a TMINLP.*/
  //@{
  /** Pass the type of the variables (INTEGER, BINARY, CONTINUOUS) to the optimizer.
     \param n size of var_types (has to be equal to the number of variables in the problem)
  \param var_types types of the variables (has to be filled by function).
  */
  virtual bool get_variables_types(Index n, VariableType* var_types);
 
  /** Pass info about linear and nonlinear variables.*/
  virtual bool get_variables_linearity(Index n, Ipopt::TNLP::LinearityType* var_types);

  /** Pass the type of the constraints (LINEAR, NON_LINEAR) to the optimizer.
  \param m size of const_types (has to be equal to the number of constraints in the problem)
  \param const_types types of the constraints (has to be filled by function).
  */
  virtual bool get_constraints_linearity(Index m, Ipopt::TNLP::LinearityType* const_types);
//@}  
    
  /** \name Overloaded functions defining a TNLP.
     * This group of function implement the various elements needed to define and solve a TNLP.
     * They are the same as those in a standard Ipopt NLP problem*/
  //@{
  /** Method to pass the main dimensions of the problem to Ipopt.
        \param n number of variables in problem.
        \param m number of constraints.
        \param nnz_jac_g number of nonzeroes in Jacobian of constraints system.
        \param nnz_h_lag number of nonzeroes in Hessian of the Lagrangean.
        \param index_style indicate wether arrays are numbered from 0 (C-style) or
        from 1 (Fortran).
        \return true in case of success.*/
  virtual bool get_nlp_info(Index& n, Index&m, Index& nnz_jac_g,
                            Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style);
  
  /** Method to pass the bounds on variables and constraints to Ipopt. 
       \param n size of x_l and x_u (has to be equal to the number of variables in the problem)
       \param x_l lower bounds on variables (function should fill it).
       \param x_u upper bounds on the variables (function should fill it).
       \param m size of g_l and g_u (has to be equal to the number of constraints in the problem).
       \param g_l lower bounds of the constraints (function should fill it).
       \param g_u upper bounds of the constraints (function should fill it).
  \return true in case of success.*/
  virtual bool get_bounds_info(Index n, Number* x_l, Number* x_u,
                               Index m, Number* g_l, Number* g_u);
  
  /** Method to to pass the starting point for optimization to Ipopt.
    \param init_x do we initialize primals?
    \param x pass starting primal points (function should fill it if init_x is 1).
    \param m size of lambda (has to be equal to the number of constraints in the problem).
    \param init_lambda do we initialize duals of constraints? 
    \param lambda lower bounds of the constraints (function should fill it).
    \return true in case of success.*/
  virtual bool get_starting_point(Index n, bool init_x, Number* x,
                                  bool init_z, Number* z_L, Number* z_U,
                                  Index m, bool init_lambda,
                                  Number* lambda);
//   
  /** Method which compute the value of the objective function at point x.
    \param n size of array x (has to be the number of variables in the problem).
    \param x point where to evaluate.
    \param new_x Is this thithe first time we evaluate functions at this point? 
    (in the present context we don't care).
    \param obj_value value of objective in x (has to be computed by the function).
    \return true in case of success.*/
  virtual bool eval_f(Index n, const Number* x, bool new_x, Number& obj_value);

  /** Method which compute the gradient of the objective at a point x.
    \param n size of array x (has to be the number of variables in the problem).
    \param x point where to evaluate.
    \param new_x Is this the first time we evaluate functions at this point? 
    (in the present context we don't care).
    \param grad_f gradient of objective taken in x (function has to fill it).
    \return true in case of success.*/
  virtual bool eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f);

  /** Method which compute the value of the functions defining the constraints at a point
    x.
    \param n size of array x (has to be the number of variables in the problem).
    \param x point where to evaluate.
    \param new_x Is this the first time we evaluate functions at this point? 
    (in the present context we don't care).
    \param m size of array g (has to be equal to the number of constraints in the problem)
    \param grad_f values of the constraints (function has to fill it).
    \return true in case of success.*/
  virtual bool eval_g(Index n, const Number* x, bool new_x, Index m, Number* g);

  /** Method to compute the Jacobian of the functions defining the constraints.
    If the parameter values==NULL fill the arrays iCol and jRow which store the position of
    the non-zero element of the Jacobian.
    If the paramenter values!=NULL fill values with the non-zero elements of the Jacobian.
    \param n size of array x (has to be the number of variables in the problem).
    \param x point where to evaluate.
    \param new_x Is this the first time we evaluate functions at this point? 
    (in the present context we don't care).
    \param m size of array g (has to be equal to the number of constraints in the problem)
    \param grad_f values of the constraints (function has to fill it).
    \return true in case of success.*/
  virtual bool eval_jac_g(Index n, const Number* x, bool new_x,
                          Index m, Index nele_jac, Index* iRow, Index *jCol,
                          Number* values);
  
  /** Method to compute the Jacobian of the functions defining the constraints.
    If the parameter values==NULL fill the arrays iCol and jRow which store the position of
    the non-zero element of the Jacobian.
    If the paramenter values!=NULL fill values with the non-zero elements of the Jacobian.
    \param n size of array x (has to be the number of variables in the problem).
    \param x point where to evaluate.
    \param new_x Is this the first time we evaluate functions at this point? 
    (in the present context we don't care).
    \param m size of array g (has to be equal to the number of constraints in the problem)
    \param grad_f values of the constraints (function has to fill it).
    \return true in case of success.*/
  virtual bool eval_h(Index n, const Number* x, bool new_x,
                      Number obj_factor, Index m, const Number* lambda,
                      bool new_lambda, Index nele_hess, Index* iRow,
                      Index* jCol, Number* values);

  
  /** Method called by Ipopt at the end of optimization.*/  
  virtual void finalize_solution(TMINLP::SolverReturn status,
                                 Index n, const Number* x, Number obj_value);
  
  //@}

  virtual const SosInfo * sosConstraints() const{return NULL;}
  virtual const BranchingInfo* branchingInfo() const{return NULL;}
  
  
  void printSolutionAtEndOfAlgorithm(){
    printSol_ = true;}



//std::cout<<"flute"<<std::endl;
void initializeData(FILE* h){
/*
  linType=1;
  varNum=10;
  varType=1;
  
  W=26019.475467;
  a.push_back(0.152216);
  a.push_back(0.118124);
  a.push_back(0.101030);
  a.push_back(0.196180);
  a.push_back(0.158531);
  a.push_back(0.118892);
  a.push_back(0.126588);
  a.push_back(0.109965);
  a.push_back(0.162577);
  a.push_back(0.117178);
  
  b.push_back(44.742557);
  b.push_back(34.944390);
  b.push_back(93.324757);
  b.push_back(62.101010);
  b.push_back(71.753105);
  b.push_back(81.207744);
  b.push_back(5.317250);
  b.push_back(16.985577);
  b.push_back(88.463985);
  b.push_back(11.739812);

  c.push_back(72.273751);
  c.push_back(77.468892);
  c.push_back(52.983122);
  c.push_back(56.186971);
  c.push_back(96.601371);
  c.push_back(36.007819);
  c.push_back(6.902601);
  c.push_back(19.031839);
  c.push_back(53.590464);
  c.push_back(94.136050);

  d.push_back(-21.229801);
  d.push_back(-56.719870);
  d.push_back(-56.428945);
  d.push_back(-47.649553);
  d.push_back(-59.898149);
  d.push_back(-46.898594);
  d.push_back(-1.138258);
  d.push_back(-12.566179);
  d.push_back(-84.440268);
  d.push_back(-26.634969);

  w.push_back(4.031705);
  w.push_back(44.109323);
  w.push_back(63.951720);
  w.push_back(55.586024);
  w.push_back(48.098622);
  w.push_back(62.538444);
  w.push_back(84.246574);
  w.push_back(60.663050);
  w.push_back(32.714690);
  w.push_back(64.449357);

for(int k=0;k<varNum;k++){
  U.push_back(100.00);
  p.push_back(0.1);
  q.push_back(0.1);
}
*/


  
fichier = h;

//  std::string nconf;  
//   std::ostringstream convert; 
//   convert << j; 
//   nconf = convert.str();
//   std::string temp = "output";
//   nconf = temp.append(nconf);
//   nconf = nconf.append(".txt");
//   
//   nomfichier = new char [nconf.length()+1];
//   std::strcpy (nomfichier, nconf.c_str());
  
}

public:
  bool printSol_;
  int linType;
  int varNum;
  int varType;
  FILE* fichier;
  double W;
  std::vector<double> U;
  std::vector<double> a;
  std::vector<double> b;
  std::vector<double> c;
  std::vector<double> d;
  std::vector<double> p;
  std::vector<double> q;
  std::vector<double> w;
  
};

#endif
