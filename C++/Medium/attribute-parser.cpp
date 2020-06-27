#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Tag {
public:
  Tag(string n) : name{n} {}

  string getName() const { return name; }
  void AddAttribute(const string &n, const string &v) {
    attributes.emplace(n, v);
  }

  string GetAttributeValue(const string &name) {
    auto findRes = attributes.find(name);
    if (findRes != attributes.end()) {
      return findRes->second;
    } else {
      return notFound;
    }
  }

  friend bool operator==(const Tag &a, const Tag &b);

private:
  string name;
  // vector<Attribute> attributes;
  map<string, string> attributes;

public:
  static const string notFound;
};

const string Tag::notFound = "Not Found!";

bool operator==(const Tag &a, const Tag &b) {
  return a.name == b.name; //  && a.attributes == b.attributes
}

vector<Tag> outerTags;

Tag GetInnerTag(const map<string, vector<Tag>> &inner, string tagName,
                string innerTagName) {
  auto findTag = inner.find(tagName);
  if (findTag == inner.end()) {
    // no such parent tag, but it's ok, as we can have tag~attribute
    auto findInnerTag =
        find(outerTags.begin(), outerTags.end(), Tag{innerTagName});
    if (findInnerTag == outerTags.end()) {
      // no such inner tag
      return Tag{""};
    }

    return *findInnerTag;
  } else {
    auto innerVer = findTag->second;
    auto findInnerTag =
        find(innerVer.begin(), innerVer.end(), Tag{innerTagName});
    if (findInnerTag == innerVer.end()) {
      // no such inner tag
      return Tag{""};
    }

    return *findInnerTag;
  }
}

void RemoveQuotesAround(string &attrVal) {
  attrVal.erase(0, 1);
  attrVal.erase(attrVal.size() - 1, 1);
}

int main() {
  int N, Q;
  cin >> N >> Q;

  stack<Tag> tags;
  map<string, vector<Tag>> innerTags;

  while (N--) {
    string tagName;
    cin >> tagName;

    tagName.erase(0, 1);

    if (tagName[0] == '/') {
      // closing tag, just remove it from top
      if (!tags.empty()) {
        tags.pop();
      }
    } else {
      // opening tag
      bool hasAttributes{true};

      if (tagName[tagName.size() - 1] == '>') {
        // no attributes for this tag
        tagName.erase(tagName.size() - 1, 1);
        hasAttributes = false;
      }

      Tag tag{tagName};

      while (hasAttributes) {
        // parse all attributes;
        string attrName;
        string eq;
        string attrVal;
        cin >> attrName >> eq >> attrVal;
        if (attrVal[attrVal.size() - 1] == '>') {
          // end of tag
          attrVal.erase(attrVal.size() - 1, 1);
          hasAttributes = false;
        }
        RemoveQuotesAround(attrVal);
        tag.AddAttribute(attrName, attrVal);
      }

      if (!tags.empty()) {
        auto topTag = tags.top();
        innerTags[topTag.getName()].push_back(tag);
      } else {
        outerTags.push_back(tag);
      }
      tags.push(tag);
    }
  }

  std::cin >> std::ws;

  while (Q--) {
    string line;
    getline(cin, line);

    string attributeName;
    auto posTilde = line.find('~');
    if (posTilde != string::npos) {
      // found tilde attribute
      auto posAtr{posTilde + 1}; // move to the first element
      attributeName = line.substr(posAtr, line.size() - posAtr);
      line.erase(posTilde); // remove everything after, so maybe add line.size()
                            // - posTilde
    } else {
      // try to find an attribute after last .
      auto posDot = line.find_last_of('.');
      if (posDot != string::npos) {
        // found tilde attribute
        auto posAtr{posDot + 1}; // move to the first element
        attributeName = line.substr(posAtr, line.size() - posAtr);
        line.erase(posDot); // remove everything after, so maybe add line.size()
                            // - posDot
      }
    }

    string tagName{""};
    Tag t{""};

    while (!line.empty()) {
      auto posDot = line.find_first_of('.');
      if (posDot != string::npos) {
        string currTagName = line.substr(0, posDot);

        if (!tagName.empty()) {
          auto tagIt = innerTags.find(tagName);
          if (tagIt == innerTags.end()) {
            cout << Tag::notFound << endl;
            break;
          } else {
            t = GetInnerTag(innerTags, tagName, currTagName);
            if (t.getName().empty()) {
              // parent tag doesn't have current tag as a child
              cout << Tag::notFound << endl;
              break;
            }
          }
        }

        tagName = currTagName;
        auto length{posDot + 1};
        line.erase(0, length);
      } else {
        // line is the name of tag
        t = GetInnerTag(innerTags, tagName, line);
        if (!t.getName().empty()) {
          cout << t.GetAttributeValue(attributeName) << endl;
        } else {
          cout << Tag::notFound << endl;
        }
        line.clear();
      }
    }
  }

  return 0;
}
