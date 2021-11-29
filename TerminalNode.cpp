#include "TerminalNode.h"

TerminalNode::TerminalNode(char lab = ' ') : label(lab)
{
    this->left = this->right = NULL;
}

TerminalNode::~TerminalNode()
{
    delete this->left;
    delete this->right;
}

bool TerminalNode::isTerminal()
{
    return true;
}

bool TerminalNode::compare(Data *data)
{
    return true;
}

char TerminalNode::getLabel()
{
    return label;
}

string TerminalNode::toString()
{
    string result;
    stringstream ss;
    ss << "[" << label << "]";
    ss >> result;
    return result;
}