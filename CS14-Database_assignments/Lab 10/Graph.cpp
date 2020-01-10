#include <vector>
#include <list>
#include <set>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <climits>
#include "Vertex.h"
#include "Graph.h"


using namespace std;

Graph::Graph(){}

Graph::Graph(ifstream& ifs)
{
    int numNodes;
    int numEdges;
    string text;
    string edgeText;

    ifs >> numNodes;

    //Number of edges is not needed. 
    ifs >> numEdges;
    ifs.ignore();
    
    for (int i = 0; i < numNodes; i++) 
    {
        getline(ifs,text);

        Vertex tempName;
        tempName.label = text;
        vertices.push_back(tempName);
    }

    int weight = 0;

    while (ifs >> edgeText) 
    {
        int temp1 = 0;
        int temp2 = 0;
        ifs >> text;
        ifs >> weight;

        for(unsigned i = 0; i < vertices.size(); ++i)
        {
            if(edgeText == vertices.at(i).label)
            {
                temp1 = i;
            }
            if(text == vertices.at(i).label)
            {
                temp2 = i;
            }
        }
    vertices.at(temp1).neighbors.push_back(make_pair(temp2,weight));
  }


}

Graph::~Graph()
{
    while (vertices.size() != 0)
    {
        vertices.pop_back();
    }

}

void Graph::output_graph(const string & fileName)
{
    ofstream outFS(fileName.c_str());
    
    if (!outFS.is_open()) 
    {
        cout << "Error opening" << fileName << endl;
        return;
    }
    outFS << "Graph:" << endl << "{" << endl;
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        if (vertices.at(i).distance != INT_MAX)
        {
            outFS << "Label: " << vertices.at(i).label << ", Distance: " <<  vertices.at(i).distance << ", Color: " << vertices.at(i).color <<"."<< endl; 
        }
        outFS << "Neighbors: " << endl;

        list<pair<int,int> >::iterator j;

        for(j = vertices.at(i).neighbors.begin(); j != vertices.at(i).neighbors.end(); j++)
        {
            if(vertices.at(i).distance != INT_MAX)
            {
                outFS << vertices.at(j->first).label << endl;
            }
        }
        outFS << endl;

    }
    outFS << endl << "}" << endl;

    string jpgFile = fileName.substr(0,fileName.size()-4)+".jpg";
    string command = "dot -Tjpg " + fileName + " -o " + jpgFile;
    system(command.c_str());
}

void Graph::bfs()
{
    vertices.at(0).distance = 0;
    queue<Vertex*> frontierQueue;
    frontierQueue.push(&vertices.at(0));
    while (!frontierQueue.empty())
    {
        Vertex* currentV = frontierQueue.front();
        frontierQueue.pop();
        currentV -> color = "GREY";
        list <pair<int, int> >::iterator it;

        for (it = currentV -> neighbors.begin(); it != currentV -> neighbors.end(); it++)
        {
            if(vertices.at(it->first).color == "WHITE")
            {
                vertices.at(it->first).prev = currentV;
                vertices.at(it->first).distance = 0;
                vertices.at(it->first).color = "GREY";
                vertices.at(it->first).distance += vertices.at(it->first).prev->distance + 1;
                frontierQueue.push(&vertices.at(it->first));
                
            }

        }


    }
}
