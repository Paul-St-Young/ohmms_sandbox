#include <iostream>
#include <assert.h>
#include "OhmmsData/Libxml2Doc.h"
//#include "OhmmsData/AttributeSet.h"

using namespace std;

/*
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <string>


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

  //// to use, make 3 lines in main()
  //string xmlfile="simple.xml";
  //ostringstream os;
  //cout << project_descriptions(os,xmlfile).str();

}
*/

ostringstream& list_nodeset(ostringstream& os, xmlDocPtr doc, xmlNodeSetPtr nodeset)
{ // for each node in nodeset, print name with text 

  // temperary variables
  xmlNodePtr cur;
  xmlChar* text;

  for (int i=0;i<nodeset->nodeNr;i++){
    cur  = nodeset->nodeTab[i];
    text = xmlNodeListGetString(doc,cur->xmlChildrenNode,1);
    os << cur->name << ": " << text << endl;
    xmlFree(text);
  }

  return os;

}

int main()
{

  // parse xml document
  Libxml2Document doc;
  bool okay = doc.parse("bcc_1.31.xml");
  assert(okay==1);

  // use xpath to search document
  OhmmsXPathObject xpath_obj = OhmmsXPathObject("//parameter",doc.getRoot());
  ostringstream os;
  list_nodeset(os,doc.getDocument(),xpath_obj.result->nodesetval);

  cout << os.str();


  return 0;
}
