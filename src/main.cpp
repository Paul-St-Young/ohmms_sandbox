#include "OhmmsData/Libxml2Doc.h"
//#include "OhmmsData/AttributeSet.h"
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <string>
#include <iostream>

using namespace std;

ostringstream& project_descriptions(ostringstream& os, string xmlfile, string xpath_exp="//project"){

  // retrieve nodeset
  xmlDocPtr doc = xmlReadFile(xmlfile.c_str(),NULL,XML_PARSE_HUGE);
  xmlXPathContextPtr context = xmlXPathNewContext(doc);
  xmlXPathObjectPtr result = xmlXPathEvalExpression((xmlChar*)xpath_exp.c_str(),context);

  // read nodeset
  xmlNodeSetPtr nodeset;
  xmlNodePtr cur;
  xmlChar* keyword;
  nodeset = result->nodesetval;
  for (int i=0;i<nodeset->nodeNr;i++){
    cur = nodeset->nodeTab[i];
    keyword = xmlNodeListGetString(doc,cur->xmlChildrenNode,1);
    os << cur->name << ": " << keyword << endl;
    xmlFree(keyword);
  }

  return os;

  /* to use, make 3 lines in main()
  string xmlfile="simple.xml";
  ostringstream os;
  cout << project_descriptions(os,xmlfile).str();
  */

}

int main(){

  Libxml2Document doc;
  bool okay = doc.parse("simple.xml");
  cout << okay << endl;

  return 0;
}
