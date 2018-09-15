class Solution {
public:
int lengthOfLongestSubstring(string s)
{
    int length = s.length();
    int position , i=-1 ;
    string s_rec ;
    int l_rec = 0 , l_old = 0;
    while(++i < length)
    {
        if((position = s_rec.find(s[i])) != string::npos)
        {
            if(l_rec > l_old)
                l_old = l_rec;
            s_rec.erase(0,position+1);
            l_rec -= position + 1;
        }
        l_rec++;
        s_rec += s[i];
    }
        if(l_rec > l_old)
        l_old = l_rec;
    return l_old;
}
};
