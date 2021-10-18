#include <string.h>
#include "TrianglesApi.hpp"
#include "UserDialog.hpp"

TrianglesApi::TrianglesApi() 
{
    m_created_triangles = new std::vector<AreaTriangle*>;
    m_user_dialog = new UserDialog();
    m_last_table = nullptr;
}

TrianglesApi::~TrianglesApi()
{
    delete static_cast<UserDialog*>(m_user_dialog);
    ClearLastTable();
    ClearTriangles();
    delete static_cast<std::vector<AreaTriangle*>*>(m_created_triangles);
}

bool TrianglesApi::AskStart() const
{
    return static_cast<UserDialog*>(m_user_dialog)->AskStart();
}

void TrianglesApi::AskTriangle()
{
    UserDialog* dialog = static_cast<UserDialog*>(m_user_dialog);
    std::unique_ptr<AreaTriangle> t = dialog->AskTriangle();
    dialog->AddTriangle(*t);
}

char* TrianglesApi::FormTrianglesTable()
{
    UserDialog* dialog = static_cast<UserDialog*>(m_user_dialog);
    std::string table = dialog->FormTrianglesTable();

    ClearLastTable();
    m_last_table = new char[table.length() + 1];
    strcpy(m_last_table, table.c_str());

    return m_last_table;
}

void* TrianglesApi::GetTriangle(const char* tr_args)
{
    AreaTriangleFactory factory;
    StringArgs input_args;
    StringArgsExtractor extractor;
    void* triangle;

    input_args.triangle_text = tr_args;
    try
    {
        triangle = static_cast<void*>(factory.GetTriangle(&input_args, &extractor));
        static_cast<std::vector<AreaTriangle*>*>(m_created_triangles)
            ->push_back(static_cast<AreaTriangle*>(triangle));
    }
    catch(const std::exception& e)
    {
        triangle = nullptr;
    }
    
    return triangle;
}

void TrianglesApi::AddTriangle(const void* triangle)
{
    const AreaTriangle* tr_ptr;
    try
    {
        tr_ptr = static_cast<const AreaTriangle*>(triangle);
    }
    catch(const std::exception& e)
    {
        throw "Provided arguments wasn't a triangle";
    }
    
    static_cast<UserDialog*>(m_user_dialog)->AddTriangle(*tr_ptr);
}

void TrianglesApi::ClearLastTable()
{
    if (m_last_table)
    {
        delete[] m_last_table;
        m_last_table = nullptr;
    }
}

void TrianglesApi::ClearTriangles()
{
    auto triangles = static_cast<std::vector<AreaTriangle*>*>(m_created_triangles);

    for (auto t : *triangles)
    {
        delete t;
    }
}
