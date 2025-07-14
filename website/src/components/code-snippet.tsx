import { Prism } from "react-syntax-highlighter";
import githubData from "@config/github-data";
import { tomorrow } from "react-syntax-highlighter/dist/cjs/styles/prism";
import type { ReactNode } from "react";

interface CodeSnippetProps {
  source: string;
  sourcePath?: string;
  language?: string;
  startMarker?: string;
  endMarker?: string;
  commentStyle?: string;
}
function innerPre(title?: string, url?: string) {
  return function InnerPre({ children }: { children: ReactNode }) {
    let titleElem: ReactNode;
    if (title && url) titleElem = (
      <a href={url} style={{ textDecoration: "none" }} target="_blank">
        {title}
      </a>
    );
    else if (title) titleElem = <p>{title}</p>;
    const border = "1px solid color-mix(in srgb, var(--sl-color-gray-5), transparent 25%)"
    return (
      <figure
        style={{
          margin: "0.5em 0",
          backgroundColor: "var(--code-bg)",
          border: border,
          borderRadius: "2px",
        }}
      >
        {title && <div style={{ padding: "0.25em 0.5em", borderBottom: border }}>{titleElem}</div>}
        <pre
          style={{
            border: "none",
            overflow: "auto",
            padding: "0.5em 1em",
            margin: 0,
          }}
        >
          {children}
        </pre>
      </figure>
    );
  };
}

function InnerCode({ children, className }: { children: ReactNode[]; className?: string }) {
  return <code className={className}>{children}</code>;
}

export default function CodeSnippet({ source, language = "cpp", commentStyle = "//", startMarker, endMarker, sourcePath }: CodeSnippetProps) {
  const lines = source.split("\n").map((l, i) => [i, l] satisfies [number, string]);
  let snippet: string;
  let startLineNum: number;
  let endLineNum: number;

  if (!(startMarker || endMarker)) {
    snippet = source;
    startLineNum = 1;
    endLineNum = lines.length + 1;
  }

  const startLine = lines.filter(([i, l]) => l.match(new RegExp(`^\\s*${commentStyle}\\s*${startMarker}\\s*$`)));
  startLineNum = startLine.length ? startLine[0][0] : -1;

  const endLine = lines.filter(([i, l]) => l.match(new RegExp(`^\\s*${commentStyle}\\s*${endMarker}\\s*$`)));
  endLineNum = endLine.length ? endLine[0][0] : lines.length + 1;

  snippet = lines
    .filter(([i, _]) => i > startLineNum && i < endLineNum)
    .map(([_, l]) => l)
    .join("\n");

  startLineNum += 2;

  let url: string | undefined;

  if (sourcePath)
    url = [githubData.repositoryAddress(), "blob", githubData.deploymentBranch, "tab", sourcePath, `#L${startLineNum}-L${endLineNum}`].join("/");

  return (
    <div style={{margin: "1em 0 2.15em 0"}}>
      <Prism
        language={language}
        showLineNumbers
        startingLineNumber={startLineNum}
        PreTag={innerPre(sourcePath, url)}
        CodeTag={InnerCode}
        codeTagProps={{
          title: sourcePath,
          href: url,
        }}
        style={tomorrow}
        useInlineStyles={false}
        lineNumberStyle={{
          paddingRight: "0.5em",
          minWidth: "2em",
        }}
      >
        {snippet}
      </Prism>
    </div>
  );
}
