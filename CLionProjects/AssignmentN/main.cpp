#include <iostream>
#include <vector>
#include <algorithm>
#include "CostumerQueue.cpp"
#include "CashierQueue.cpp"
#include "cmp.cpp"
using namespace std;
void firsttype();

void Full_FillCashiersNodes(CashierQueue queue,CostumerQueue costumerQueue);

void processingCashierQueue( CostumerQueue queue, CashierQueue cashierQueue, CostumerQueue costumerQueue);

void sort_Queue(CostumerQueue queue);

void recursive_fullfill(CashierQueue queue, CostumerQueue queue1, CostumerQueue queue2);

int main() {
    firsttype();


    return 21;
}
void secondtype(){

}








void firsttype(){
    CostumerQueue costumerque;
    costumerque.enqueue(21,2,10,6);
    costumerque.enqueue(40,4,12,7);
    costumerque.enqueue(10,5,21,12);
    costumerque.enqueue(14,6,12,5);
    costumerque.enqueue(40,7,12,7);
    costumerque.enqueue(10,8,21,12);
    costumerque.enqueue(14,9,12,5);
    
    cout<<costumerque.toString();

    int numberofCashier=3;
    int numberofBarista=numberofCashier/3;

    CashierQueue cashierQueue;
    cashierQueue.createCashierQueue(numberofCashier);

    cout<<"\nPrint Cashier queue at first:\n"+cashierQueue.toString();

    CostumerQueue ForCashier_Costumerque;
    ForCashier_Costumerque.clonequeue(costumerque.head,costumerque.last);

    cout<<"Print  Costumer queue for arrive time:\n"+ForCashier_Costumerque.toStringforarrivetime();
    cout<<"\nPrint  Costumer queue for order time:\n"+ForCashier_Costumerque.toStringforOrderTime();


    // Full_FillCashiersNodes( cashierQueue,costumerque);
    // recursive fullfill

    CostumerQueue All_Costumer_AfterCashiers;
    recursive_fullfill(cashierQueue,costumerque,All_Costumer_AfterCashiers);

    //cout<<"cashierQueue get node"<<cashierQueue.getNode()->name<<endl;

    if(cashierQueue.getNode()== nullptr&&!costumerque.isEmpty()){
        //     cout<<"\nCounting while 2\n";

        processingCashierQueue( costumerque, cashierQueue, All_Costumer_AfterCashiers);
        //cout<<"\nCounting while 2\n";

    }
    sort_Queue(All_Costumer_AfterCashiers);

}



void recursive_fullfill(CashierQueue queue, CostumerQueue costumerQueue, CostumerQueue All_after) {
    node* n=queue.getNode();
    CostumerNode* costumerNode=costumerQueue.dequeue();

    if(n== nullptr||costumerNode== nullptr) return ;

    //cout<<"Recursive fullfill is working \n";

    queue.skiptimeforinitial(costumerNode->arrivetime-queue.prevnodearrivetime);
    queue.prevnodearrivetime=costumerNode->arrivetime;
    costumerNode->setoutofCashier(n->timeofprecostumer- costumerNode->arrivetime);

    All_after.enqueueNode(costumerNode);

    n->timeofprecostumer=costumerNode->outofcashier;
    n->isworking= true;
    n->setwork(costumerNode->ordertime);

    recursive_fullfill(queue,costumerQueue,All_after);

}
void recursive_Continious(CashierQueue queue, CostumerQueue costumerQueue, CostumerQueue All_after){

}
int mintimeofcashier;
node* cnode;
CostumerNode* costnode;
void processingCashierQueue( CostumerQueue queue, CashierQueue cashierQueue, CostumerQueue all_aftercash) {

    mintimeofcashier=cashierQueue.findmintime();
    costnode=queue.dequeue();

    //cout<<"\nMin time of Cashier:"+ to_string(mintimeofcashier)<<endl;

    if(mintimeofcashier==-1||queue.isEmpty()||costnode== nullptr)return;

    cnode=cashierQueue.skiptime(mintimeofcashier);

    //  cout<<"\nProcc while 2\n";

    all_aftercash.enqueueNode(costnode);
    // cout<<"\nProcc while 2\n";
    //cout<<"\nCostnode order time "+ to_string(costnode->ordertime) +"\n";
    cout<<"\ncnode->timeofprecostumer time of Cashier "+ to_string(cnode->timeofprecostumer) +"\n";
   // if(cnode== nullptr)cout<<"cNode Nullptr\n";
    cnode->setwork(costnode->ordertime);
    //cout<<"\nProcc while 2\n";

    costnode->setoutofCashier(cnode->timeofprecostumer-costnode->arrivetime);
    cnode->timeofprecostumer=costnode->outofcashier;

    processingCashierQueue(queue,cashierQueue,all_aftercash);
    sort_Queue(all_aftercash);

}
void Full_FillCashiersNodes(CashierQueue queue,CostumerQueue costumerQueue ){
    //typedef node CashierNode;
    node* Chead=queue.head;
    CostumerNode* costumerNode;
    CostumerQueue All_Costumer_AfterCashiers;
    int arrivetime;
    while(Chead!= nullptr&&!costumerQueue.isEmpty()){
        //cout<<"\nCounting while\n";
        costumerNode=costumerQueue.dequeue();

        Chead->isworking= true;
        Chead->setwork(costumerNode->ordertime);

        costumerNode->setoutofCashier(0);
        Chead->timeofprecostumer=costumerNode->outofcashier;

        All_Costumer_AfterCashiers.enqueueNode(costumerNode);
        // arrivetime=costumerNode->arrivetime;
        Chead=Chead->next;
    }
    //  recursive_fullfill(queue,costumerQueue,All_Costumer_AfterCashiers);
    // cout<<"Chead node:"<<Chead->isworking<<endl;
    if(Chead== nullptr&&!costumerQueue.isEmpty()){
        //     cout<<"\nCounting while 2\n";

        processingCashierQueue( costumerQueue, queue, All_Costumer_AfterCashiers);
        //cout<<"\nCounting while 2\n";

    }
  //  cout<<"\ntry place size of All_Costumer_AfterCashiers:"<<All_Costumer_AfterCashiers.dequeue()->outofcashier<<endl;

    sort_Queue(All_Costumer_AfterCashiers);

}

void sort_Queue(CostumerQueue queue) {//sorting que up to outofCashier

    vector<CostumerNode*> vectorofCN;
    CostumerNode* temp=queue.head;



    while (temp!= nullptr){
        cout<<temp->outofcashier<<endl;
        vectorofCN.push_back(queue.dequeue());
       temp=queue.head;
    }

    sort(vectorofCN.begin(),vectorofCN.end(),cmp());
    //cout<<"\ntry place \n";

    for(int i = 0; i < vectorofCN.size(); i++)
    {  queue.enqueueNode(vectorofCN[i]);
        cout<<vectorofCN[i]->outofcashier<<endl;
    }


}


