#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    set<int > st;
    set<int> st1;
    //set<int>::iterator a,b;   //iterator of set
    st.insert(3);
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    st.insert(7); //st.emplace(7);
    
    //print
    cout<<"set element from st :"<<endl;
    for (auto i : st)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "size of set  " << st.size() << endl;
    for(auto it:st1)
    {
      cout<<it<<" ";
    } cout<<endl;

    // st.erase(7);   //erase 7 element
    // st.erase(st.begin());
    // cout<< st.count(8);  //count 8 but it always 1 in set duplicate not allowed
    /*auto it=st.begin();
   it++;
   for(auto i=it;i!= st.end();i++)
   {
     cout<<*i<<" ";
   }*/
    /*
   auto it=st.begin();
   advance(it,4);   //fourth index element or 5th element
   cout<<*it<<endl;  */
    // auto it =st.find(7);
    // cout<<*it<<endl;
    auto a = st.begin();
    cout << "first element or smallest element " << *a << endl;
    auto b = st.rbegin();
    cout << "last element or greater element " << *b << endl;

  
}