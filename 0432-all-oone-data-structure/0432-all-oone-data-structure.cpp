class AllOne {
public:
    unordered_map<string  , int>  mym;
set<pair<int , string>> mys;
    AllOne() {
        
    }
    
    void inc(string key) {
        if(mym.find(key) != mym.end()) 
        {
            auto x = mym[key];
            mys.erase({x , key});
        }
        mym[key]++;
        mys.insert({mym[key] , key});
    }
    
    void dec(string key) {
        auto x = mym[key];
        if(x == 1)
        {
            mym.erase(key);
            mys.erase({x , key});
        }
        else 
        {
             mys.erase({x , key});
            mym[key]--;
            mys.insert({mym[key] , key});
        }
    }
    
    string getMaxKey() {
       if(mys.size()>0) return mys.rbegin()->second;
       return "";
    }
    
    string getMinKey() {
          if(mys.size()>0) return mys.begin()->second;
       return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */