#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//test prof de la curs(B..eheehe) 2024 :(

enum Party{ Republican, Democratic,Independent};

class ElectionCandidate {
private:
	Party party = Party::Independent;
	char* name=nullptr;
	int votes = 0;
	const string region;
	static int TotalCandidates;
	const static int NAME_MIN_SIZE;
public:
	//define for candidate name a public interface. thse set meth will validate that the received title has more than 3 characters, oth. throw except. use a static variable for the magic nr 
	void setName(const char* name) {
		if (strlen(name) < ElectionCandidate::NAME_MIN_SIZE) {
			throw exception("invalid name");
		}
		if (this->name != nullptr) {
			delete[]this->name;
		}
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	char* getName() {
		if (this->name == nullptr) {
			return nullptr;
		}
		char* copy = new char[strlen(name) + 1];
		strcpy_s(copy, strlen(name) + 1, name);
		return copy;
	}
	//ctr
	ElectionCandidate(const char* name, Party party, int votes, string region):region(region),votes(votes),party(party ){
		this->setName(name);
		ElectionCandidate::TotalCandidates += 1;
	}
	~ElectionCandidate() {
		delete[]this->name;
		ElectionCandidate::TotalCandidates -= 1;
	}
	ElectionCandidate(const ElectionCandidate& candidate) :region(candidate.region), votes(candidate.votes), party(candidate.party) {
		this->setName(candidate.name);
		ElectionCandidate::TotalCandidates += 1;
	}
	void operator=(const ElectionCandidate& candidate) {
		if (this == &candidate) {
			return;
		}
		this->setName(candidate.name);
		this->votes = candidate.votes;
		this->party = candidate.party;
	}
	static int getNoCandidates() {
		return ElectionCandidate::TotalCandidates;
	}
	ElectionCandidate operator++() {
		this->votes += 1;
		return *this;
	}
	bool operator==(ElectionCandidate& c) {
		if (this->party == c.party && strcmp(this->name, c.name) == 0) {
			return true;
		}
		else { 
			return false;
		}
	}
	bool checkName(string value) {
		if (strcmp(this->name, value.c_str()) == 0) {
			return true;
		}
		else { return false; }
	}
	float getPopularityIndex() {
		float weight = 0;
		switch (this->party) {
		case Party::Independent:
			weight = 1.5;
			break;
		case Party::Democratic:
			weight = 1.2;
			break;
		case Party::Republican:
			weight = 1;
			break;
		default:
			weight = 0;
		}
		return weight * this->votes;
	}
	friend void operator <<(ostream& console, ElectionCandidate& candidate);
};
void operator<<(ostream& console, ElectionCandidate& candidate) {
	console << endl << candidate.name << "|" << candidate.votes << "|" << candidate.party << "|" << candidate.region;
}
int ElectionCandidate::TotalCandidates = 0;
const int ElectionCandidate::NAME_MIN_SIZE = 3;
int main() {
	ElectionCandidate john("john", Party::Republican, 2000, "alabama");
	cout << endl << john.getName();
	john.setName("john test");
	cout << endl << "name:" << john.getName();

	//test destructor
	ElectionCandidate* candidate =
		new ElectionCandidate("john", Party::Republican, 2000, "alabama");
	delete candidate;

	ElectionCandidate johnClone = john;
	cout << endl << johnClone.getName();
	ElectionCandidate temp("bob", Party::Republican, 2000, "alabama");
	temp = john;
	cout << endl << temp.getName();
	cout << endl << "total candidates:" << ElectionCandidate::getNoCandidates();
	cout << john;
	cout << temp;
	temp.setName("bob");
	if (john == temp) {
		cout << endl << "the same";
	}
	else { cout << endl << "different";
	}
	if (john.checkName("john")) {
		cout << endl << "same name";
	}
	else { cout << endl << "diff name";
	}
	cout << endl << "popularity" << john.getPopularityIndex();
	ofstream file("candidate.txt");
	if (file.is_open()) {
		file << john;
		file.close();
	}
	else {
		throw exception("file error");
	}
	return 0;

}