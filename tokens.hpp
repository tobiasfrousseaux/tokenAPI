#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   int i = 0, t = 0;
   while (s[i]!='\0')
   {
      t = charCount(s,sep);
      i++;
   }
   return t+1;
}

void addToken(string& s,char sep,string t)
{
   if (s!="\0")
   {
      s = s + ' ' + sep + ' ' + t;
   }
   else
      s = t;
}

string getTokenAt(string s,char sep, int i)
{
   string t;
   int tc = tokenCount(s,sep);      // tc es token count, cantidad de tokens
   int ps, us;    // ps primer separador , us ultimo separador
   if (i==0)
   {
      ps = indexOf(s,sep);    // no tiene separador al inicio por lo tanto el ps es el del final
      t = substring(s, i, ps);
   }
   if (i==(tc-1))
   {
      ps = indexOfN(s,sep,(tc-1));
      t = substring(s, ps+1);    // no tiene separador al final por lo tano no tiene us
   }
   if( i!=0 and i!=(tc-1) )
   {
      ps = indexOfN(s,sep,i);
      us = indexOfN(s,sep,(i+1));
      t = substring(s, (ps+1), (us-1));
   }
   return t;
}

void removeTokenAt(string& s,char sep, int i)
{
   int tc = tokenCount(s,sep);
   string ssa, ssd;
   string t = getTokenAt(s,sep,i);
   int ti = indexOf(t,sep,0), tf = lastIndexOf(t,sep);
   int tim = indexOfN(t, sep, i), tfm = indexOfN(t, sep, (i+1));
   if (i==0)
   {
      s = substring(s, (ti-1));
   }
   if (i==(tc-1))
   {
      s = substring(s,0,ti);
   }
   if (i!=0 and i!=(tc-1))
   {
      ssa = substring(s, 0, tim);
      ssd = substring(s, tfm);
      s = ssa + ssd;
   }
}

void setTokenAt(string& s,char sep, string t,int i)
{
}

int findToken(string s,char sep, string t)
{
   return 0;
}

#endif
