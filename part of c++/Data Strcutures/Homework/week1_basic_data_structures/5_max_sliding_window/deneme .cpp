#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll number_of_elements,i,k;
    cin>>number_of_elements;
    ll a[number_of_elements];
    for(i=0;i<number_of_elements;i++)
    {
        cin>>a[i];
    }      
    cin>>k;
    vector<ll> answer;
    deque<ll> q;
    for(i=0;i<number_of_elements;i++)
    {
        if(i>=k)
        {
            answer.push_back(a[q.front()]);
            while((!q.empty()) && (q.front()<=i-k))
            q.pop_front();
        }
        while((!q.empty()) && (a[q.back()]<=a[i]))
        q.pop_back();
        q.push_back(i);
    }
    answer.push_back(a[q.front()]);
    for(i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*
wedrftgyhujıopşçmyntbgrvfdrgbthnyulopınytrvecfedvrbtynumöıço9pumyjbrgecsdcfvrgbthnymukıçl9plömukyjtbrgvcwdqxwcfevgrbhtnyjmkuölıç
fevgrbthnyjmuköçoşıölukytnhrbgevfvgrbhtnjymkuöılço.şğ0*
ağlafbghtnyjmuk4.oşğpıöukyjgf bghjymuöço.şıöukytnhrg
tmağlaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

ağla ama ağla 
for(int i=0; ;i++){
    printf("ağla\n");
}
duyduğuma göre ağlıyormuşsun 
nooo seni gördüğüm için gözlerim kamaştı ışıl ışılsın
>:( <3 >:(( <3333333333333333333333333333333333333333333333333333333333333333 mızmızlanma >:( >:(((((((((((((((((((((((( yerim seniiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii>:(ağla beni kırdın özür dilerim sadece şakaydııııı kırdı9kn küstüm sana, ciddi manada söylemedim biliyon dimi ciddiydin yoooo 41at piyasada yok ben sana neden koş mızmızlanmayı ciddi söyleyim ağla ıngaaaaaaaküstüm acıktım sen makarna ben seni no ben seni sen bebi hmmmmmmmm nefis gözüküyo of makatina istiyom >:( fağlaa küstüm 



*/
