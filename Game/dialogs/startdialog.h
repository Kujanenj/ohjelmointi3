#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>
#include <QPixmap>
#include "dialogs/sizedialog.h"

namespace Ui {
class startdialog;
}
/**
 * @brief The startdialog class Selector dialog for the game start.
 */
class startdialog : public QDialog
{
    Q_OBJECT

public:
    explicit startdialog(QWidget *parent = nullptr);
    ~startdialog();
public slots:
    void setXY(int xy);
signals:
    void size(int, int);

private slots:

    /*!
     * \brief on_startButton_clicked starts the game
     */

    void on_startButton_clicked();
    /*!
     * \brief on_mapSizeButton_clicked Opens a new dialog for selecting mapsize
     */
    void on_mapSizeButton_clicked();
    /*!
     * \brief on_QuitButton_clicked Quits the game
     */
    void on_QuitButton_clicked();

private:
    Ui::startdialog *ui;
    int x_=10;
    int y_=10;
    SizeDialog SizeDialog_;

};

#endif // STARTDIALOG_H
