#include <iostream>
#include <list>

using namespace std;

/*cvladi dabali tirit tu bolovdeba mashin is klasis wevria !!
funqciis argumentebisgan advilad gasamijnad*/
class Graph
{
	int vertex_quantity_; /* wveroebis raodenoba*/
	list<int>* vertices_adjacents_; /* wveroebis mosazgvre wveroebi*/
	int* vertices_visited_; /*masivi wveros mdgomareobis shesanaxad*/
	enum colors{WHITE = 0, GREY = 1, BLACK = 2}; /*WHITE-aghmoucheneli wvero
												   GREY-aghmochenili wvero
												   BLACK-sheswavlili wvero*/
	int  time_; /*bijebis raodenoba*/
	int* time_discovering_; /* aghmochenis dro*/
	int* time_exploring_; /* sheswavlis dro*/

	void DFSUtility_(int vertex_current, int vertices_visited[]);
public:
	Graph(int vertex_quantity);
	void addEdge_(int vertex_from, int vertex_to);
	void DFS_(int vertex_root);
	void print_();
};

Graph::Graph(int vertex_quantity)
{
	this->vertex_quantity_ = vertex_quantity;
	vertices_adjacents_ = new list<int>[vertex_quantity_];
}

void Graph::addEdge_(int vertex_from, int vertex_to)
{
	vertices_adjacents_[vertex_from].push_back(vertex_to);
}

void Graph::DFS_(int vertex_root) 
{
	vertices_visited_ = new int[vertex_quantity_];
	time_exploring_ = new int[vertex_quantity_];  /*wveroebis aghmochenis da */
	time_discovering_ = new int[vertex_quantity_]; /*sheswavlis droebis chasawerad*/
	
	/*tavidan yvelaferi gavanulot*/
	time_ = 0;
	for (int i = 0; i < vertex_quantity_; i++)
	{
		vertices_visited_[i] = WHITE; /*yvela wvero aghmouchenelia*/
		time_exploring_[i] = 0;
		time_discovering_[i] = 0;
	}

	DFSUtility_(vertex_root, vertices_visited_);
	for (int i = 0; i < vertex_quantity_; i++)
		if (vertices_visited_[i] == WHITE)
			DFSUtility_(i, vertices_visited_);
}

void Graph::print_()
{
	for (int i = 0; i < vertex_quantity_; i++)
	{
		std::cout << "Wvero: " << i << "\tAgmochenis dro: " << time_discovering_[i] \
			<< "\tSheswavlis dro: " << time_exploring_[i] << endl;
	}
}

void Graph::DFSUtility_(int vertex_current, int vertices_visited[])
{
	vertices_visited[vertex_current] = GREY; /*mimdinare wvero gavxadot aghmochenili*/
	time_ = time_ + 1; /*aghmochenis dro gaizrdeba yovel bijze*/
	time_discovering_[vertex_current] = time_; /*chaiwereba mimdinare wveros aghmochenis dro*/
	
	

	for (auto i = vertices_adjacents_[vertex_current].begin(); i != vertices_adjacents_[vertex_current].end(); i++)
		if (vertices_visited[*i] == WHITE) 
			DFSUtility_(*i, vertices_visited); 

	/**/
	vertices_visited[vertex_current] = BLACK; /*mimdinare wvero gavxadot sheswavlili*/
	time_ = time_ + 1;
	time_exploring_[vertex_current] = time_;
}

int main()
{
	Graph g(6);
	g.addEdge_(0, 1);
	g.addEdge_(1, 2);
	g.addEdge_(2, 3);
	g.addEdge_(4, 3);
	g.addEdge_(4, 2);
	g.addEdge_(5, 2);

	g.DFS_(0);
	g.print_();

	system("PAUSE");
	return 0;
}
