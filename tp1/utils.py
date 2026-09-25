"""Fonctions utilitaires pour le TP 1 (SAheart) : chargement, style et figures."""
from pathlib import Path

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

_ICI = Path(__file__).resolve().parent


def style():
    """Style homogène pour toutes les figures."""
    plt.rcParams.update({
        "figure.figsize": (8, 5),
        "figure.dpi": 100,
        "axes.spines.top": False,
        "axes.spines.right": False,
        "axes.grid": True,
        "grid.alpha": 0.3,
        "font.size": 10,
    })


def load_saheart(chemin=None):
    """Charge SAheart (462 x 10), famhist recodée 0/1 (Present = 1)."""
    chemin = Path(chemin) if chemin else _ICI / "SAheart.csv"
    df = pd.read_csv(chemin, index_col="row.names")
    df["famhist"] = (df["famhist"] == "Present").astype(int)
    return df


def plot_saheart_apercu(df=None):
    """Histogramme de chaque variable, par classe (0 = sain, 1 = malade)."""
    if df is None:
        df = load_saheart()
    variables = [c for c in df.columns if c != "chd"]
    fig, axes = plt.subplots(3, 3, figsize=(12, 9))
    for ax, v in zip(axes.ravel(), variables):
        for k, couleur, nom in [(0, "tab:blue", "sain"), (1, "tab:red", "malade")]:
            ax.hist(df.loc[df.chd == k, v], bins=20, alpha=0.5,
                    color=couleur, label=nom, density=True)
        ax.set_title(v)
    axes[0, 0].legend()
    fig.suptitle("SAheart : distribution de chaque variable par classe")
    fig.tight_layout()
    return fig


def comparer_frontieres(modeles, X, y, noms=("x1", "x2"), resolution=300):
    """Ajuste chaque modèle sur X (2 colonnes) et trace sa frontière de décision.

    modeles : dict {titre: estimateur non ajusté}
    """
    x_min, x_max = X[:, 0].min(), X[:, 0].max()
    y_min, y_max = X[:, 1].min(), X[:, 1].max()
    dx, dy = 0.05 * (x_max - x_min), 0.05 * (y_max - y_min)
    xx, yy = np.meshgrid(np.linspace(x_min - dx, x_max + dx, resolution),
                         np.linspace(y_min - dy, y_max + dy, resolution))
    grille = np.c_[xx.ravel(), yy.ravel()]

    fig, axes = plt.subplots(1, len(modeles), figsize=(5 * len(modeles), 4.5),
                             squeeze=False)
    for ax, (titre, modele) in zip(axes[0], modeles.items()):
        modele.fit(X, y)
        z = modele.predict(grille).reshape(xx.shape)
        ax.contourf(xx, yy, z, alpha=0.2, levels=[-0.5, 0.5, 1.5],
                    colors=["tab:blue", "tab:red"])
        ax.contour(xx, yy, z, levels=[0.5], colors="k", linewidths=1.5)
        ax.scatter(X[y == 0, 0], X[y == 0, 1], s=12, c="tab:blue",
                   label="sain", edgecolor="none")
        ax.scatter(X[y == 1, 0], X[y == 1, 1], s=12, c="tab:red",
                   label="malade", edgecolor="none")
        erreur = np.mean(modele.predict(X) != y)
        ax.set_title(f"{titre} (erreur app. {erreur:.1%})")
        ax.set_xlabel(noms[0])
        ax.set_ylabel(noms[1])
    axes[0, 0].legend()
    fig.tight_layout()
    return fig
