\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{spiral}

\def\sinolShortNameText{Skr\'ot}
\def\sinolRAMText{Limit pami\k eci}
\def\sinolTimeText{Limit czasu}
\def\sinolInputText{Wej\'scie dla testu}
\def\sinolOutputText{Wyj\'scie dla testu}
\def\sinolOtherSamplesText{Inne testy przyk\l adowe}
\def\sinolSubtaskText{Podzadanie}
\def\sinolPointsText{Punkty}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% English language version                                % 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\DeclareOption{en}{%
\def\sinolLang{english}
%\selectlanguage{english}

\def\sinolShortNameText{Short name}
\def\sinolRAMText{Memory limit}
\def\sinolTimeText{Time limit}
\def\sinolInputText{Input for test}
\def\sinolOutputText{Output for test}
\def\sinolOtherSamplesText{Other example tests}
\def\sinolSubtaskText{Subtask}
\def\sinolPointsText{Points}

}

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{article}}
\ProcessOptions\relax
\LoadClass{article}

\usepackage[a4paper, includeheadfoot, margin=40pt, footskip=\dimexpr\headsep+\ht\strutbox\relax, bmargin = \dimexpr60pt+2\ht\strutbox\relax,]{geometry}

\usepackage[utf8]{inputenc}
\usepackage{cmbright}
\usepackage{newtxmath}
\usepackage{amsfonts, amsmath, amssymb}
\usepackage[T1]{fontenc}

\usepackage{multirow}
\usepackage{graphicx}
\usepackage{tabularx}
\usepackage{verbatim}
\usepackage{fancyvrb}
\usepackage{lastpage}
\usepackage{bbding}
\usepackage{tikz}
\usepackage{hyperref}

% removes section numbers
\renewcommand{\@seccntformat}[1]{}


\def\ifdef#1{\ifcsname#1\endcsname}

% header
\def\makeheader{%
  \raisebox{15px}{
  \hspace{-20px}
  \begin{minipage}[b][50px]{0.85\textwidth}
  \hspace{2px}
  {\LARGE \bf \title} \\
  \begin{small}
  \begin{tabularx}{\textwidth}{Xrl}
    & \ifdef{id} \sinolShortNameText: & \bf \id \fi \\
    \bf \contest & \ifdef{TL} \sinolTimeText: &  \bf \TL \fi \\
    \desc & \ifdef{ML} \sinolRAMText: & \bf \ML \fi \\
  \end{tabularx}
  \end{small}
  \end{minipage}
  \begin{minipage}[b][50px]{0.15\textwidth}
  \hspace{15px}\raisebox{3px}{\includegraphics[height=60px]{logo.png}}
  \end{minipage}
  }
  \vspace{-25px}
  \hrule
  \vspace{12px}
}

\newcommand\includefile[1]{
  \vspace{-0.7em}
  \VerbatimInput[frame=single]{#1}
}

\newcommand\example[1]{
  \begin{center}%
  \begin{minipage}[t]{0.45\textwidth}%
  \vspace{0pt}%
      \noindent \sinolInputText {\tt \id#1}:%
      \includefile{../in/\id#1.in}%
  \end{minipage}\hfill%
  \begin{minipage}[t]{0.1\textwidth}%
  \end{minipage}%
  \begin{minipage}[t]{0.45\textwidth}%
  \vspace{0pt}%
      \noindent \sinolOutputText {\tt \id#1}:%
      \includefile{../out/\id#1.out}
  \end{minipage}%
  \end{center}%
}

\newcommand\fullexample[1]{
  \noindent \sinolInputText {\tt \id#1}:%
  \includefile{../in/\id#1.in}%

  \noindent \sinolOutputText {\tt \id#1}:%
  \includefile{../out/\id#1.out}
}

\newcommand\note[1]{
  \noindent {\bf Explena:} #1
}

\newenvironment{ocen}{%
  \subsection{\sinolOtherSamplesText}
  \begin{itemize}
}{
  \end{itemize}
}%

\newcommand\testocen[2]{
   \item[-] test {\tt \id#1}: #2
}

\newenvironment{grading}{

\begin{center}
\begin{tabular}{|c|c|}
\hline
\textbf{\sinolSubtaskText} & \textbf{\sinolPointsText}\\ \hline
}{
\end{tabular}
\end{center}
}

\newcommand\gradingrow[2]{
  #1 & #2 \\ \hline
}

\newcommand\twocol[2]{%
\begin{center}%
\begin{minipage}[t]{0.5\textwidth}%
\vspace{0pt}%
{#1}%
\end{minipage}\hfill%
\begin{minipage}[t]{0.5\textwidth}%
\vspace{0pt}%
{#2}%
\end{minipage}%
\end{center}}
