// (C) Copyright Carnegie Mellon University 2006
// All Rights Reserved.
// This code is published under the Common Public License.
//
// Authors :
// P. Bonami, Carnegie Mellon University
//
// Date :  03/17/2006
#include "MyTMINLP.hpp"
#include "/home/thierry/Bonmin-stable/build/include/coin/BonAmplInterface.hpp"
#include <cmath>
#include <math.h>


bool 
MyTMINLP::get_variables_types(Index n, VariableType* var_types){
  
   if (varType == 0) {
	for (int i=0; i<varNum; i++) {
	   var_types[i] = CONTINUOUS;
	   }
    }

   else if (varType == 1) {
	for (int i=0; i<varNum; i++) {
	   var_types[i] = INTEGER;
	   }
   }

   return true;
	
}


bool 
MyTMINLP::get_variables_linearity(Index n, Ipopt::TNLP::LinearityType* var_types)
{
  
   for (int i=0; i<varNum; i++) { 
	var_types[i] = Ipopt::TNLP::NON_LINEAR;
  }

  return true;
}


bool 
MyTMINLP::get_constraints_linearity(Index m, Ipopt::TNLP::LinearityType* const_types)
{

	assert (m==1);

  if (linType == 0) 
	{
	const_types[0] = Ipopt::TNLP::NON_LINEAR;
	}  
  else
	{
	const_types[0] = Ipopt::TNLP::LINEAR;
	}
  return true;
}

bool 
MyTMINLP::get_nlp_info(Index& n, Index&m, Index& nnz_jac_g,
                       Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style)
{
  
  n = varNum;//number of variable
  m = 1;//number of constraints
  nnz_jac_g = varNum;//number of non zeroes in Jacobian
  nnz_h_lag = varNum;//number of non zeroes in Hessian of Lagrangean
  index_style = TNLP::FORTRAN_STYLE;
	return true;
}

bool 
MyTMINLP::get_bounds_info(Index n, Number* x_l, Number* x_u,
                            Index m, Number* g_l, Number* g_u)
{

  assert(n==varNum);
  assert(m==1);
  
  for(int i=0; i<varNum; i++) {
if (varType == 0) {
	for (int i=0; i<varNum; i++) {
	   x_l[i] = 0.;
  	   x_u[i] = U[i];
	   }
    }

   else if (varType == 1) {
	for (int i=0; i<varNum; i++) {
	   x_l[i] = 0;
  	   x_u[i] = U[i];
	   }
   }
  
  }

  g_l[0] = -DBL_MAX;
  g_u[0] = W;
	return true;
}

bool 
MyTMINLP::get_starting_point(Index n, bool init_x, Number* x,
                             bool init_z, Number* z_L, Number* z_U,
                             Index m, bool init_lambda,
                             Number* lambda)
{

  assert(n==varNum);
  assert(m==1);
  
  assert(init_x);
  assert(!init_lambda);
  
	for (int i=0; i<varNum; i++) {
	   x[i] = 0;
	   }
   
	return true;
}

bool 
MyTMINLP::eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{

  assert(n==varNum);
  obj_value = 0.;
     for(int i=0; i<n; i++) {
     obj_value = obj_value - c[i]/(1. + b[i]*exp(-a[i]*(x[i] + d[i])));
     }
	return true;
}

bool
MyTMINLP::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
  assert(n==varNum);
  for(int i=0; i<n; i++) {
       grad_f[i] = - a[i]*b[i]*c[i]*exp(-a[i]*(x[i] + d[i]))/pow(1. + b[i]*exp(-a[i]*(x[i] + d[i])),2);
       }

	return true;
}

bool
MyTMINLP::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{

  assert(n==varNum);
  assert(m==1);
  
  g[0] = 0;
  if (linType == 0) {
     for(int i=0; i<n; i++) {
	g[0] = g[0] + sqrt(p[i]*x[i] + q[i]) - sqrt(q[i]);
     }
  }

  else if (linType == 1) {
     for(int i=0; i<n; i++) {
	g[0] = g[0] + w[i]*x[i];
     }
}

	return true;
}

bool
MyTMINLP::eval_jac_g(Index n, const Number* x, bool new_x,
                     Index m, Index nnz_jac, Index* iRow, Index *jCol,
                     Number* values)
{
  
  assert(n==varNum);
  assert(nnz_jac == n);
  if(values == NULL) {
    for(int i=0; i<n; i++) {
       iRow[i] = 1;
       jCol[i] = i+1;
    }
    	
	return true;
  }

  else if(linType == 0) {
        for(int i=0; i<n; i++) {
           values[i] = p[i]/(2*sqrt(p[i]*x[i] + q[i])) ;
        }
}
  else {
           for(int i=0; i<n; i++) {
              values[i] = w[i];
              }

     }
	return true;
  }


bool
MyTMINLP::eval_h(Index n, const Number* x, bool new_x,
                 Number obj_factor, Index m, const Number* lambda,
                 bool new_lambda, Index nele_hess, Index* iRow,
                 Index* jCol, Number* values)
{
  assert (n==varNum);
  assert (m==1);
  assert(nele_hess==varNum);
  if(values==NULL)
  {
    for(int i=0; i<n; i++) {
      iRow[i] = i+1;
      jCol[i] = i+1;
      }

  }
  else {
	if(linType == 0) {
        	for(int i=0; i<n; i++) {
           		values[i] = -lambda[0]*p[i]*p[i]/(4*pow(sqrt(p[i]*x[i] + q[i]),3)) - obj_factor*a[i]*a[i]*b[i]*c[i]*exp(-a[i]*(x[i]+d[i]))* (-1.+b[i]*exp(-a[i]*(x[i]+d[i])))/pow(1.+b[i]*exp(-a[i]*(x[i]+d[i])),3);
        	}
	}
	else {
        	for(int i=0; i<n; i++) {
           		values[i] = - obj_factor*a[i]*a[i]*b[i]*c[i]*exp(-a[i]*(x[i]+d[i]))*(-1.+b[i]*exp(-a[i]*(x[i]+d[i])))/pow(1.+b[i]*exp(-a[i]*(x[i]+d[i])),3);
        	}
	}
    
   }
  
	return true;
}

void
MyTMINLP::finalize_solution(TMINLP::SolverReturn status,
                            Index n, const Number* x, Number obj_value)
{

  fprintf(fichier, "Problem status: %d \n", status);

  fprintf(fichier, "Objective value: %f \n", obj_value);
  
 if(printSol_ && x != NULL){
   fprintf(fichier, "Solution: ");
   
    for(int i = 0 ; i < n ; i++){
      fprintf(fichier, "x[%d",i);
      fprintf(fichier, "] = %f",x[i]);
       if(i < n-1){
       fprintf(fichier, ",");
       }
    }
   fprintf(fichier, "\n");
  
  }
}
