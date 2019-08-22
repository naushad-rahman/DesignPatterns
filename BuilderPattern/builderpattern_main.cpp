#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
struct HtmlBuilder;

struct HTMLElements
{
    string name, text;
    vector<HTMLElements> elements;
    const size_t indent_size = 2;
    HTMLElements() {}
    HTMLElements(const string &name, const string &text) : name(name), text(text) {}

    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
            oss << string(indent_size * (indent + 1), ' ') << text << endl;

        for (const auto &e : elements)
            oss << e.str(indent + 1);

        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }

   static unique_ptr<HtmlBuilder> build(string root_name)
  {
    return make_unique<HtmlBuilder>(root_name);
  }
};

struct HtmlBuilder
{
    /* data */
    HTMLElements root;
    HtmlBuilder (string root_name)
    {
        root.name=root_name;
    }

    HtmlBuilder& add_child(string child_name , string child_text)
    {
        HTMLElements e(child_name,child_text);
        root.elements.emplace_back(e);
        return *this;
    }

    string str() const 
    {
        return root.str();
    }
};


int main(int, char **)
{
    std::cout << "Hello, world!\n";


    HtmlBuilder builder{"Ul"};
    builder.add_child("li","Hello").add_child("li","world");
    
    cout<<builder.str()<<'\n';


}
