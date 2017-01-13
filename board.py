# Basic definition for computer Go, python version, Tristen Wentling
from __future__ import division
from random import randint
from player import Player

# might need to just make an overflow bound to simplify checking parameters
class Board(object):
    """defines a basic board for computer Go"""
    #  methods:
    #       random_moves
    #       opp_move
    #       comp_move
    #       analyze_board
    #       is_empty
    #       is_corner
    #       is_edge
    #       valid_move
    #       display
    #       choose_colors

    def __init__(self, size):
        """sets up an empty board of size x size"""
        self._columns = []
        self._dimension = size
        self._def_rand_moves = int(2*(size**2)/3)
        self._player1 = Player()
        self._player2 = Player()
        for i in xrange(size):
            self._columns.append([])
            self._columns[i] = list('.' for x in xrange(size))

    def random_moves(self):
        """generate some random moves"""
        for i in xrange(self._def_rand_moves):
            try:
                coin = randint(0, 1)
                if (coin == 0):
                    token = 'X'
                    x = randint(0, self._dimension - 1)
                    y = randint(0, self._dimension - 1)
                    if (self.valid_move(x, y)):
                        self._columns[x][y] = token
                else:
                    token = 'o'
                    x = randint(0, self._dimension - 1)
                    y = randint(0, self._dimension - 1)
                    if (self.valid_move(x, y)):
                        self._columns[x][y] = token
            except:
                pass

    def choose_colors(self):
        choices = ["B", "W"]
        self._player1.set_pid(choices[(randint(0,1))])
        self._player1.set_pid(choices[0])

    def opp_move(self):
        """make opponent move"""
        pass

    def comp_move(self):
        """self generate move"""
        pass

    def analyze_board(self):
        """basic board analysis"""
        #  need to expand, clustering algorithm to analyze by groups
        #  will try to use kmeans algorithm, need to think about implementation details
        opponent_counter1 = 0
        self_counter1 = 0
        opponent_counter2 = 0
        self_counter2 = 0
        for i, j in xrange(self._dimension):
            if (i < round(self._dimension / 2)):
                if (self._columns[i][j] == 'X'):
                    opponent_counter += 1
                elif (self._columns[i][j] == '+'):
                    self_counter += 1
            else:
                if (self._columns[i][j] == 'X'):
                    opponent_counter += 1
                elif (self._columns[i][j] == '+'):
                    self_counter += 1
        if opponent_counter1 < self_counter1:
            side = 1
        else:
            side = 2
        return side

    def is_empty(self, x, y):
        """check whether intersection is in liberty"""
        if self.columns[x][y] == '.':
            return True
        else:
            return False

    def is_edge(self, x, y):
        """checks if liberty is on edge"""
        if ((x == 0) or (y == 0) or (x == self._dimension - 1) or (y == self._dimension - 1)):
            return True
        else:
            return False

    def is_corner(self, x, y):
        """checks if liberty is in corner"""
        edges = 0
        if x == 0:
            edges += 1
        if y == 0:
            edges += 1
        if x == self._dimension - 1:
            print x  # ---------------------------------------------------------debugging
            edges += 1
        if y == self._dimension - 1:
            edges += 1
        if edges == 2:
            return True
        else:
            return False

    def check_squares(self, x, y):
        """check whether surrounding squares are occupied"""
        pass

    def valid_move(self, x, y):  #currently having issues====================
        """check whether a move is valid"""
        #  check if liberty is in ko
        baddies = 0
        if (x != 0 ): #  check square left
            print "here 1"  # -----------------------------------------------------------debugging
            if self.is_empty(self._columns[x - 1][y]) is False:
                baddies += 1
                print baddies
        if (x != self._dimension - 1): # check square right
            print "here 2"  # -----------------------------------------------------------debugging
            if self.is_empty(self._columns[x + 1][y]) is False:
                baddies += 1
        if (y != 0):  #  check square above
            print "here 3"  # -----------------------------------------------------------debugging
            if self.is_empty(self._columns[x][y - 1]) is False:
                baddies += 1
        if (y != self._dimension - 1): #  check square below
            print "here 4"  # -----------------------------------------------------------debugging
            if self.is_empty(self._columns[x][y + 1]) is False:
                baddies += 1
        print baddies
        if (is_edge(x, y)):
            if is_corner(x, y) and (baddies == 2):
                return False
            elif baddies == 3:
                return False
        elif baddies == 4:
            return False
        else:
            print "it is True \n"  # -------------------------------------------debugging
            return True

    def display(self):
        for i in xrange(self._dimension):
            print self._columns[i], '\n'
