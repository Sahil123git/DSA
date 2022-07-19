	int isNegativeWeightCycle(int n, vector<vector<int>>edges){ //Bellman–Ford Algorithm
	    vector<int> DistVctr(n,INT_MAX); //initiailize every node dist with infinity
	    DistVctr[0] = 0; //dist to source node is 0
	    
	    for(int i = 0; i < n - 1; i++) { //This loop will iterate (V-1) times
	        for(auto edge:edges) { //chk every edge and update also with shoretest dist
	            if(DistVctr[edge[0]] != INT_MAX && DistVctr[edge[0]] + edge[2] < DistVctr[edge[1]]) {
	                DistVctr[edge[1]] = DistVctr[edge[0]] + edge[2];
	            }
	        }
	    }
	    
	    for(auto edge:edges) { //this will if there are -ve weight cycle or not
	        if(DistVctr[edge[0]] + edge[2] < DistVctr[edge[1]]) { //if we can still chgn  dist of DistVctr
	            return 1; //means Negative wgt cycle exist
	        }
	    }
	    return 0;
	}