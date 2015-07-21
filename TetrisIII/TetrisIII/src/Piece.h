class Piece {
private:
    void _initializeMatrix();           // Assigns values to matrix[7][4][5][5].
 
public:
    Piece();                            // Default constructor.
    int matrix[7][4][5][5];             // Matrix containing all pieces in every rotation
};