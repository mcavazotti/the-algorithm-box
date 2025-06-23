import { createTheme, extendTheme } from "@mui/material";

export const TABTheme = createTheme({
  colorSchemes: {
    light: {
      palette: {
        mode: "light",
        primary: {
          main: "#5d4037",
        },
        secondary: {
          main: "#00897b",
        },
        background: {
          default: "#fff8e1",
          paper: "#fff5cc",
        },
      },
    },
    dark: {
      palette: {
        mode: "dark",
        primary: {
          main: "#ffcc80",
        },
        secondary: {
          main: "#4db6ac",
        },
        background: {
          default: "#221b1b",
          paper: "#1c1a17",
        },
      },
    },
  },
  cssVariables: {
    colorSchemeSelector: "class",
  },

  typography: {
    fontFamily: "Montserrat",
  },
  spacing: 4,
  shape: {
    borderRadius: 0,
  },
});
