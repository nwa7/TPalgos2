#include "tp6.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
    for (int i = 0; i < nodeCount; i++){
                this->appendNewNode(new GraphNode(i));
    }

    for (int i = 0; i < nodeCount; i++){
        for (int j = 0; j < nodeCount ; j++){
            if (adjacencies[i][j] != 0){
                this->nodes[i]->appendNewEdge(this->nodes[j],adjacencies[i][j]);
            }
        }
    }

    /**
      * Make a graph from a matrix
      * first create all nodes, add it to the graph then connect them
      * this->appendNewNode
      * this->nodes[i]->appendNewEdge
      */
}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
    nodes[nodesSize]=first;
    visited[first->value]=true;
    nodesSize+=1;
    for (Edge *e=first->edges; e != nullptr ; e= e->next){
         if (!visited[e->destination->value]){
            deepTravel(e->destination, nodes, nodesSize,visited);
         }
    }
    /**
      * Fill nodes array by travelling graph starting from first and using recursivity
      *
      * deepTravel(GraphNode* f irst, GraphNode* nodes[ e, int& nodesSize, bool visited[ e) : rem-
pli le tableau nodes en parcourant le graphe en profondeur à partir de f irst. nodeSize est le
nombre de noeud dans nodes et est donc égale à 0 lors du premier appel de fonction. visited
est un tableau de booléen rempli de f alse lors du premier appel.

      */

}


void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
    /**
     * Fill nodes array by travelling graph starting from first and using queue
     * nodeQueue.push(a_node)
     * nodeQueue.front() -> first node of the queue
     * nodeQueue.pop() -> remove first node of the queue
     * nodeQueue.size() -> size of the queue
     */
    std::queue<GraphNode*> nodeQueue;
    nodeQueue.push(first);

    while(!nodeQueue.empty()){
        nodes[nodesSize] = nodeQueue.front();
        visited[nodes[nodesSize]->value] = true;
        nodesSize+=1;
        nodeQueue.pop();
        for (Edge* e = first->edges; e!= nullptr; e = e->next){
            if(!visited[e->destination->value]){
                nodeQueue.push(e->destination);
            }
        }
    }
}



bool Graph::detectCycle(GraphNode *first, bool visited[])
{
    /**
      Detect if there is cycle when starting from first
      (the first may not be in the cycle)
      Think about what's happen when you get an already visited node
    **/

    visited[first->value] = true;
    for (Edge* e = first->edges; e!= nullptr; e = e->next){
        if(visited[e->destination->value]){
            return true;
        }
        else{
            if (detectCycle(e->destination, visited)){
                return true;
            }
        }
    }
    return false;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 150;
    w = new GraphWindow();
    w->show();

    return a.exec();
}
