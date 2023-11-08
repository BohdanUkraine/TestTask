#ifndef DATABASEOPERATIONS_H
#define DATABASEOPERATIONS_H


class DataBaseOperations
{
public:
    DataBaseOperations(class QString name);
    void insertData(class QString hash, float percent, QString path);
    class QImage getLastImage();
    void getDataAt(QImage& image, float& percent, int index);
    int getCount();

private:
    class QSqlDatabase* db;
};

#endif // DATABASEOPERATIONS_H
