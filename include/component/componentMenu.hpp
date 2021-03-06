#ifndef COMPONENTMENU_HPP_
# define COMPONENTMENU_HPP_

#include "../component/componentWindow.hpp"

/** 
 * \enum e_infoSprite
 * \brief enum contenant le type de sprite (Utile pour savoir si le jouer choisis de jouer ou de load ou de quitter ou n'importe quoi)
 * \author pixies
 */

typedef enum class e_infoSprite {
  NONE, /* INITIALISATION */
    USELESS, /* Concerne le background */
    PLAY, /* Pour commencer à jouer */
    OPTIONS, /* Options du jeux */
    CREDITS /* RAC TAVUH */
    }		t_infoSprite;


/** 
 * \struct e_RectCoorSprite
 * \brief struct recode de sf::Rect pour les int (à refaire vite fait avec les templates) de la sfml avec une information suplementaire sur le sprites en question 
 * \author pixies
 */

typedef struct	s_RectCoorSprite {
  int		rectLeft; /* Left coordinate of the rectangle */
  int		rectTop; /* Top coordinate of the rectangle */
  int		rectWidth; /* Width of the rectangle */
  int		rectHeight; /* Height of the rectangle */
  t_infoSprite	who; /* Valeur du sprite */
}		e_RectCoorSprite;

/** 
 * \class t_InfSprite
 * \brief struct  Permet d'avoir une information suplementaire par rapport au sprite mit
 * \author pixies
 */

typedef struct	s_InfSprite
{
  sf::Sprite	sprite;
  t_infoSprite	who;
}		t_InfSprite;


/** 
 * \class componentMenu
 * \brief Class abstraite component du menu
 * \author pixies
 */

class	componentMenu
{
public : 
  virtual ~componentMenu() = default;

protected :

  /** 
   * \fn createSprites
   * \brief Crée les sprites et les push dans le vector de sprites
   * \author pixies
   */

  virtual   void		createSprites() = 0;

  
  /** 
 * \fn fillRect
 * \brief Remplie le vecteur de structure e_RectCoorSprite avec tout les sprites ajouté
 * \author pixies
 */

  virtual   void		fillRect() = 0;

  /** 
 * \fn drawSprites
 * \brief affiche les sprites du vecteur
 * \author pixies
 */
  
  virtual void		drawSprites() = 0;


  /** 
 * \fn keyboardMouseMenu
 * \brief event clavier ou souris
 * \author pixies
 */
  
  virtual void		keyboardMouseMenu() = 0;

  /** 
 * \fn isContainMySprites
 * \brief Fait une rectangulation des coordonée fournis avec les coordoné situé dans le vector de e_RectCoorSprite (recode de la fonction contain de la sfml)
 * \param int x coordonnée X pointé par la souris int y coordonnéé y pointé par la souris
 * \return true si un poin a été trouver, false sinon
 * \author pixies
 */

  virtual  bool		isContainsMySprites(int x , int y) = 0;


  /* Event */
  
  sf::Event			_event;

  /* vector de sprite */
  std::vector<t_InfSprite>	_sprites;

  /* vector de rectangle de sprite */
  std::vector<e_RectCoorSprite>	_vCoorSprites;

};

#endif /* !COMPONENTMENU_HPP_ */
