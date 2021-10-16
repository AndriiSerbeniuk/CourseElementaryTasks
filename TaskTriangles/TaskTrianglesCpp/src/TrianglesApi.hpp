#pragma once

// API for outside use of the library
class TrianglesApi
{
public:
    TrianglesApi();
    ~TrianglesApi();

    bool AskStart() const;
    void AskTriangle();
    char* FormTrianglesTable();

    void* GetTriangle(const char* tr_args);
    void AddTriangle(const void* triangle);

private:
    void* m_user_dialog;
    char* m_last_table;
    void* m_created_triangles;

    void ClearLastTable();
    void ClearTriangles();
};
